#include <iostream>

using namespace std;

int N;
int nums[101];

// i번째 숫자를 연산했을 때, j의 값이 나오는 개수
long long dp[101][21];

int main() 
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	dp[1][nums[1]] = 1;

	for (int i = 2; i < N; i++)
	{
		// 연산결과는 0 이상이므로, 0부터 해야 한다.
		for (int j = 0; j <= 20; j++)
		{

			// 더하기
			if (j + nums[i] >= 0 && j + nums[i] <= 20 && dp[i - 1][j] > 0)
			{

				dp[i][j + nums[i]] += dp[i - 1][j];

			}
			// 빼기
			if (j - nums[i] >= 0 && j - nums[i] <= 20 && dp[i - 1][j] > 0)
			{

				dp[i][j - nums[i]] += dp[i - 1][j];

			}
		}
	}

	cout << dp[N-1][nums[N]];

    return 0;
}