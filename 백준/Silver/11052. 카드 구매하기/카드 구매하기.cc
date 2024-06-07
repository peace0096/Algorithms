#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int p[1001];
int dp[1001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> p[i];
	}

	dp[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}
	
	cout << dp[N];

	/*
	dp[0] = 0
	dp[1] = 1
	dp[2] = 5 or 1 + 1
	dp[3] = 6 or 5 + (1 + 1) or 1 * 3	
	dp[4] = 7 or 6 + 1 * 3 or 5 + 5
	*/

	


	return 0;
}
