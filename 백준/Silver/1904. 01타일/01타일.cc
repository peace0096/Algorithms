#include <iostream>
#include <vector>

using namespace std;
int N;
long long dp[1000001];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	dp[1] = 1;	// 1
	dp[2] = 2;	// 11, 00
	dp[3] = 3;	// 100, 001, 111
	dp[4] = 5;	// 1001, 1111, 1100, 0011, 0000
	dp[5] = 8;	// 10011, 11111, 11001, 00111, 00001, 10000, 00100, 11100

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N];
	
	return 0;
}
