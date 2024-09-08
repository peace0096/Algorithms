#include <iostream>
using namespace std;

int board[100][100];
long long dp[100][100];
int N;

int main() 
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    dp[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0 || dp[i][j] == 0) continue;
            int next_col = i + board[i][j];
            int next_row = j + board[i][j];

            if (next_col < N) dp[next_col][j] += dp[i][j];
            if (next_row < N) dp[i][next_row] += dp[i][j];
        }
    }

    cout << dp[N - 1][N - 1];

    return 0;
}