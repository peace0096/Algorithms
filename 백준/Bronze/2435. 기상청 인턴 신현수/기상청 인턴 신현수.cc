#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int N, K;
int arr[100];
int dp[100][100];

void input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void sol()
{
    int ans = INT_MAX * (-1);
    for (int i = 0; i <= N - K ; i++)
    {
        int result = 0;
        for (int j = i; j < i + K; j++)
        {
            result += arr[j];
        }
        ans = max(ans, result);
    }
    cout << ans;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

