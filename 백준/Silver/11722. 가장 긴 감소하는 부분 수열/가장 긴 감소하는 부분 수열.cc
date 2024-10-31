#include <iostream>
using namespace std;

int N;
int arr[1000];
int dp[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int ans = 1;
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j] && dp[i] <= dp[j])
            {
                dp[i]++;
                ans = max(ans, dp[i]);
            }

        }

    }
    cout << ans;

    
    return 0;
}

