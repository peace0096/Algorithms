#include <string>
#include <vector>
#include <iostream>
using namespace std;

int convert(string len_str)
{
    string min_str = len_str.substr(0, 2);
    string sec_str = len_str.substr(3, 2);
    
    int min = stoi(min_str);
    int sec = stoi(sec_str);
    
    return min * 60 + sec;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int video_len_integer = convert(video_len);
    int pos_integer = convert(pos);
    int op_start_integer = convert(op_start);
    int op_end_integer = convert(op_end);
    
    for(auto& command : commands)
    {
        // 오프닝 위치인지 확인하기
        if(pos_integer >= op_start_integer && pos_integer < op_end_integer)
        {
            pos_integer = op_end_integer;
        }
        
        // 명령 수행
        if(command[0] == 'n')
        {
            cout << "앞으로" << '\n';
            pos_integer += 10;
            if(pos_integer > video_len_integer) pos_integer = video_len_integer;
        }
        else if(command[0] == 'p')
        {
            cout << "뒤로" << '\n';
            pos_integer -= 10;
            if(pos_integer < 0) pos_integer = 0;
        }
    }
    
    if(pos_integer >= op_start_integer && pos_integer < op_end_integer)
    {
        pos_integer = op_end_integer;
    }
    
    int min = pos_integer / 60;
    int sec = pos_integer % 60;
    
    string min_str = to_string(min);
    string sec_str = to_string(sec);

    
    if(min / 10 == 0)
    {
        min_str.insert(min_str.begin(), '0');
    }
    if(sec / 10 == 0)
    {
        sec_str.insert(sec_str.begin(), '0');
    }
    
    answer += min_str;
    answer += ":";
    answer += sec_str;
    
    return answer;
}