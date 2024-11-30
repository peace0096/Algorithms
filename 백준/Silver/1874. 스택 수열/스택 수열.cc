#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int n;
queue<char> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    queue<int> q;
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int now = 1;
    while (!q.empty())
    {
        int next = q.front();
        

        if (!s.empty())
        {
            if (s.top() > next)
            {
                cout << "NO";
                return 0;
            }
            while (s.top() < next)
            {
                s.push(now++);
                ans.push('+');
            }
        }
        else
        {
            s.push(now++);
            ans.push('+');
            continue;
        }

        ans.push('-');
        s.pop();
        q.pop();
    }

    while (!ans.empty())
    {
        cout << ans.front() << '\n';
        ans.pop();
    }

    return 0;
}

