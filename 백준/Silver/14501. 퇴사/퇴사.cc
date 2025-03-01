#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int N;
int T[17];
int P[17];
int dp[17];

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }
}

void sol()
{
    for (int i = 1; i <= N + 1; i++)
    {
        
        dp[i] = max(dp[i], dp[i - 1]);
        if (T[i] + i > N + 1) continue;
        dp[T[i] + i] = max(dp[T[i] + i], dp[i] + P[i]);
    }
    cout << dp[N + 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    

    
    return 0;
}

