#include <iostream>
using namespace std;

int T;
int nums[10000];
int dp[10001];

int main() 
{
    int max_num = 0;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> nums[i];
        max_num = max(max_num, nums[i]);
    }


    dp[1] = 1; // 1
    dp[2] = 2; // 1+1, 2
    dp[3] = 3; // 1+1+1, 2+1, 3
    dp[4] = 4; // 1+1+1+1, 2+1+1, 3+1, 2+2
    dp[5] = 5; // 1+1+1+1+1, 2+1+1+1, 3+1+1, 2+2+1, 3+2
    dp[6] = 7; // 1+1+1+1+1+1, 2+1+1+1+1, 3+1+1+1, 2+2+1+1, 3+2+1, 3+3, 2+2+2
    dp[7] = 8;

    // dp[i] = dp[i - 4] + dp[i - 3] - dp[i - 2];

    for (int i = 4; i <= max_num; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] - dp[i - 3];
        if (i % 3 == 0) dp[i]++;
    }
    
    for (int i = 0; i < T; i++)
    {
        cout << dp[nums[i]] << '\n';
    }

    return 0;
}