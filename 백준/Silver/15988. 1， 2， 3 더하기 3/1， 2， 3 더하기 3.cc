#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int T;

long long dp[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;

    for (int i = 5; i <= 1000000; i++)
    {
        dp[i] = dp[i - 1] % 1000000009 + dp[i - 2] % 1000000009 + dp[i - 3] % 1000000009;
    }

    while (T--)
    {
        int x;
        cin >> x;
        cout << dp[x] % 1000000009 << '\n';
    }

    return 0;
}

