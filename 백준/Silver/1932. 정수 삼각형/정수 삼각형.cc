#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> arr[501];
int dp[501][501] = { 0, };


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }
    
    dp[0][0] = arr[0][0];
    int max_value = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j < i)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
            }
            
            if (j - 1 >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
            }
        }

        
    }

    for (int i = 0; i < N; i++)
    {
        max_value = max(max_value, dp[N - 1][i]);
    }
    cout << max_value;

    return 0;
}

