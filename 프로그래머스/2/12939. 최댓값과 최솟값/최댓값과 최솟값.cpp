#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int max_num = INT_MIN;
int min_num = INT_MAX;

string solution(string s) {
    string answer = "";
    
    int idx = 0;
    while(idx < s.size())
    {
        int num = 0;
        // 음수일 경우
        if(s[idx] == '-')
        {
            string target = "-";
            idx++;
            while(s[idx] != ' ') target += s[idx++];
            num = stoi(target);
        }
        else
        {
            string target = "";
            while(s[idx] != ' ') target += s[idx++];
            num = stoi(target);
        }
        max_num = max(max_num, num);
        min_num = min(min_num, num);
        idx++;
    }
    
    answer += to_string(min_num) + " " + to_string(max_num);
    return answer;
}