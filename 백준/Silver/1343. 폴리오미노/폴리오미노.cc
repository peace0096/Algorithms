#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

string s;
string ans;

void input()
{
    cin >> s;
}

void sol()
{
    int idx = 0;

    while (idx < s.size())
    {
        if (s[idx] == '.')
        {
            ans += '.';
            idx++;
            continue;
        }

        bool BB = false;
        bool AAAA = false;
        // BB 검증
        if (idx + 1 < s.size() && s[idx] == 'X' && s[idx + 1] == 'X')
        {
            BB = true;
        }

        // AAAA 검증
        if (BB && idx + 3 < s.size() && s[idx + 2] == 'X' && s[idx + 3] == 'X')
        {
            AAAA = true;
        }

        // 아예 못 쓰면 
        if (!BB && !AAAA)
        {
            cout << -1;
            return;
        }
        else if (AAAA)
        {
            ans += "AAAA";
            idx += 4;
        }
        else if (BB)
        {
            ans += "BB";
            idx += 2;
        }
        

        
    }

    cout << ans;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();
    
    
    return 0;
}

