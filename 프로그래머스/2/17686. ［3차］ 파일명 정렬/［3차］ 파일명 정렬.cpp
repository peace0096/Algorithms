#include <string>
#include <vector>
#include <queue>

using namespace std;

string s_head = "";
string s_num = "";

void split_s(string& s)
{
    s_head = "";
    s_num = "";
    // HEAD와 NUM 구분
    bool s_head_end = false;
    bool s_num_end = false;

    for(int i = 0; i < s.size(); i++)
    {
        string t = "";
        t += s[i];
        try
        {
            int num = stoi(t);
            // 숫자 발견
            if(!s_head_end)
            {
                s_head_end = true;
            }
            if(!s_num_end)
            {
                // num이라면
                s_num += s[i];
            }
        }
        catch(std::exception e)
        {
            // 문자 발견
            if(!s_head_end)
            {
                // 아직 head임
                s_head += s[i];
            }
            else
            {
                s_num_end = true;
                break;
            }
        }
    }
}



struct comp
{
    bool operator()(pair<string, int>& s1, pair<string, int>& s2)
    {
        split_s(s1.first);
        string s1_head = s_head;
        string s1_num = s_num;
        
        split_s(s2.first);
        string s2_head = s_head;
        string s2_num = s_num;
        
        
        int min_head_size = min(s1_head.size(), s2_head.size());
        
        for(int i = 0; i < min_head_size; i++)
        {
            if(toupper(s1_head[i]) > toupper(s2_head[i])) return true;
            else if(toupper(s1_head[i]) < toupper(s2_head[i])) return false;

        }
        
        if(s1_head.size() != s2_head.size()) return s1_head.size() > s2_head.size();
        
        
        // 같을 경우
        int s1_num_integer = stoi(s1_num);
        int s2_num_integer = stoi(s2_num);
        
        if (s1_num_integer == s2_num_integer) 
        {
            return s1.second > s2.second;
        }
        
        return s1_num_integer > s2_num_integer;

        
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
    
    int i = 0;
    for(auto& file : files)
    {
        pq.push({file, i++});
    }
    
    while(!pq.empty())
    {
        pair<string, int> a = pq.top();
        pq.pop();
        answer.push_back(a.first);
    }
    
    
    return answer;
}