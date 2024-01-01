#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int dp[1001];

int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n] ;


	return 0;
}

// 1: 1
// 2: 2
// 3: 3
// 4: 5