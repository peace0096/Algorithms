#include <iostream>
#include <vector>

using namespace std;
int N;
pair<long long, long long> dp[91];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// first : 끝 자리가 0인 이친수 개수
	// second : 끝 자리가 1인 이친수 개수

	dp[1] = {0, 1};	//1						0 1
	dp[2] = {1, 0};	//1 0					1 0
	dp[3] = {1, 1};	//10 0, 10 1			1
	dp[4] = {2, 1}; // 100 0, 101 0, 100 1	1
	dp[5] = {3, 2}; // 10000, 1010 0, 1010 1, 1001 0, 1000 1		2

	for (int i = 4; i <= N; i++)
	{
		dp[i] = { dp[i - 1].first + dp[i - 1].second, dp[i - 1].first };
	}

	cout << (dp[N].first + dp[N].second);
	return 0;
}
