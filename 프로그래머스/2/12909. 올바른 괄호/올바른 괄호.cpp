#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(string s) {
    bool answer = true;
    stack<char> c_stack;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            c_stack.push(s[i]);
        }
        else
        {
            char c = c_stack.size() > 0 ? c_stack.top() : '0';
            if (c == '(')
            {
                c_stack.pop();
            }
            else
            {
                return false;;
            }
        }
    }

    if (!c_stack.empty())
        return false;

    return answer;
}