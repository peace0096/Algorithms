#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt_0 = 0;
    int cnt_convert = 0;
    
    while(s.size() > 1)
    {
        int cnt_1 = 0;
        for(auto c : s)
        {
            if(c == '1') cnt_1++;
            else cnt_0++;
        }
        
        // 이진수 구하기
        string bit_str = "";
        while(cnt_1 >= 1)
        {
            if(cnt_1 % 2 == 0)
            {
                bit_str.insert(bit_str.begin(), '0');
            }
            else
            {
                bit_str.insert(bit_str.begin(), '1');
            }
            cnt_1 /= 2;
        }
        s = bit_str;
        cnt_convert++;
    }
    
    answer.push_back(cnt_convert);
    answer.push_back(cnt_0);
    return answer;
}