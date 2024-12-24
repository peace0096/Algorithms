#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int graph[100000][3];
int dp[100000][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;

    while (true)
    {
        int N;
        cin >> N;

        if (N == 0) break;

        for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++)
            cin >> graph[i][j];

        // 초기값
        dp[0][0] = INT_MAX;
        dp[0][1] = graph[0][1];
        dp[0][2] = graph[0][1] + graph[0][2];

        for (int i = 1; i < N; i++)
        {
            dp[i][0] = min({ dp[i - 1][0], dp[i - 1][1] }) + graph[i][0];
            dp[i][1] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0]}) + graph[i][1];
            dp[i][2] = min({ dp[i - 1][1], dp[i - 1][2], dp[i][1]}) + graph[i][2];
        }
        cout << T++ << ". " << dp[N - 1][1] << '\n';
    }

    return 0;
}

