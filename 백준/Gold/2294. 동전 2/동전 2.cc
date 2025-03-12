#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;

int N, K;
int coins[1000];
int dp[10001];

void input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> coins[i];

}


void sol()
{
    fill(dp, dp + K + 1, INT_MAX);
    sort(coins, coins + N);
    
    for (int i = coins[0]; i <= K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == coins[j]) dp[i] = 1;
            if (dp[i] != INT_MAX && i + coins[j] <= K) dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
        }

    }
    
    if (dp[K] == INT_MAX) cout << -1;
    else cout << dp[K];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();


    return 0;
}

