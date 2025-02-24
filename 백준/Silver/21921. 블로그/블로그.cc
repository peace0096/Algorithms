#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int X, N;
int users[250000];

void input()
{
    cin >> N >> X;;
    for (int i = 0; i < N; i++) cin >> users[i];
}

void sol()
{
    int left = 0;
    int right = 0;
    int now_users = 0;
    int max_users = 0;
    int cnt = 0;

    for (; right < N; right++)
    {
        now_users += users[right];
        if (right - left + 1 > X)
        {
            now_users -= users[left++];
        }
        if (max_users < now_users)
        {
            cnt = 1;
            max_users = now_users;
        }
        else if (max_users == now_users)
        {
            cnt++;
        }
    }

    if (max_users == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << max_users << '\n' << cnt;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // X일동안 가장 많이 들어온 방문자 수, 그 기간
    input();
    sol();
    
    return 0;
}

