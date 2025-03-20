#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<pair<int, string>> q;
    q.push({-1, begin});
    
    while(!q.empty())
    {
        
        int cnt = q.size();
        
        if(answer > words.size()) return 0;
        
        while(cnt > 0)
        {
            cnt--;
            int now = q.front().first;
            string now_str = q.front().second;
            q.pop();
            
            if(now_str == target)
            {
                return answer;
            }
            
            for(int i = 0; i < words.size(); i++)
            {
                // 한 글자만 다른 것인지 확인하기
                int diff = 0;
                for(int j = 0; j < now_str.size(); j++)
                {
                    if(now_str[j] != words[i][j]) diff++;
                }
                if(diff == 1)
                {
                    // 변경 가능
                    q.push({i, words[i]});
                }
            }
            
            
        }
        
        answer++;
    }
    
    
    
    
    return 0;
}