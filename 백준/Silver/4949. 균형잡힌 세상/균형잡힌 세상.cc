#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<char> s;

void Clear()
{
    while (!s.empty())
    {
        s.pop();
    }
}

int main()
{
    
    while (true)
    {
        string line;
        getline(cin, line);
        
        bool flag = true;

        for (int i = 0; i < line.size(); i++)
        {
            char now = line[i];
            if (i == 0 && now == '.') return 0;
            

            if (now == '.')
            {
                // 문장의 마지막
                if (s.size() > 0) cout << "no" << '\n';
                else cout << "yes" << '\n';
                Clear();
                break;
            }

            if ( now == '[' || now == '(')
            {
                s.push(now);
            }
            else if (now == ']')
            {
                if (s.size() > 0 && s.top() == '[')
                {
                    // Pass
                    s.pop();
                }
                else
                {
                    cout << "no" << '\n';
                    Clear();
                    break;
                }
            }
            else if (now == ')')
            {
                if (s.size() > 0 && s.top() == '(')
                {
                    // Pass
                    s.pop();
                }
                else
                {
                    cout << "no" << '\n';
                    Clear();
                    break;
                }
            }

        }
    }


    return 0;
}

