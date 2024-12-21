#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int T;

int dirX[2] = {0, 1};
int dirY[2] = {1, 0};
long long dp[201][201];
long long num = 1000007;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // w, h : 크기
    // x1, y1 : 토스트 가게 위치
    int w, h, x1, y1;
    cin >> w >> h >> x1 >> y1;
    dp[1][1] = 1;
    
    for (int i = 1; i <= y1; i++) for (int j = 1; j <= x1; j++)
    {
        if (i == 1 && j == 1) continue;
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % num;
    }
    long long home_to_toast = dp[y1][x1];

    for (int i = 1; i <= y1; i++) for (int j = 1; j <= x1; j++)
        dp[i][j] = 0;

    dp[y1][x1] = 1;
    for (int i = y1; i <= h; i++) for (int j = x1; j <= w; j++)
    {
        if (i == y1 && j == x1) continue;
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % num;
    }
    long long toast_to_school = dp[h][w];

    
    cout << (home_to_toast * toast_to_school) % num << '\n';
    
    
    return 0;
}

