#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int dp[1025][1025] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int num;
            cin >> num;
            // dp[i][j] = (i, 1)부터 (i, j)까지의 합
            dp[i][j] += dp[i][j - 1] + num;
        }
    }


    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;
        for (int j = x1; j <= x2; j++)
        {
            result += dp[j][y2] - dp[j][y1 - 1];
        }
        cout << result << '\n';

    }

   
    
    

    return 0;
}

