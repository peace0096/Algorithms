#include <iostream>

using namespace std;

int N;
int SCV[4];
int dp[61][61][61];


void DP(int a, int b, int c)
{
	int first = (a - 9) > 0 ? a - 9 : 0;
	int second = (b - 3) > 0 ? b - 3 : 0;
	int third = (c - 1) > 0 ? c - 1 : 0;
}


int main()
{
	SCV[1] = 0;
	SCV[2] = 0;
	SCV[3] = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> SCV[i];

	dp[0][0][0] = 0;

	for (int i = 0; i <= SCV[1]; i++)
	{
		for (int j = 0; j <= SCV[2]; j++)
		{
			for (int k = 0; k <= SCV[3]; k++)
			{
				{
					int first = (i - 9) > 0 ? i - 9 : 0;
					int second = (j - 3) > 0 ? j - 3 : 0;
					int third = (k - 1) > 0 ? k - 1 : 0;

					dp[i][j][k] = dp[first][second][third] + 1;
				}

				{
					int first = (i - 9) > 0 ? i - 9 : 0;
					int second = (j - 1) > 0 ? j - 1 : 0;
					int third = (k - 3) > 0 ? k - 3 : 0;

					dp[i][j][k] = min(dp[i][j][k], dp[first][second][third] + 1);
				}

				{
					int first = (i - 1) > 0 ? i - 1 : 0;
					int second = (j - 9) > 0 ? j - 9 : 0;
					int third = (k - 3) > 0 ? k - 3 : 0;

					dp[i][j][k] = min(dp[i][j][k], dp[first][second][third] + 1);
				}

				{
					int first = (i - 3) > 0 ? i - 3 : 0;
					int second = (j - 9) > 0 ? j - 9 : 0;
					int third = (k - 1) > 0 ? k - 1 : 0;

					dp[i][j][k] = min(dp[i][j][k], dp[first][second][third] + 1);
				}

				{
					int first = (i - 3) > 0 ? i - 3 : 0;
					int second = (j - 1) > 0 ? j - 1 : 0;
					int third = (k - 9) > 0 ? k - 9 : 0;

					dp[i][j][k] = min(dp[i][j][k], dp[first][second][third] + 1);
				}

				{
					int first = (i - 1) > 0 ? i - 1 : 0;
					int second = (j - 3) > 0 ? j - 3 : 0;
					int third = (k - 9) > 0 ? k - 9 : 0;

					dp[i][j][k] = min(dp[i][j][k], dp[first][second][third] + 1);
				}

				
			}
		}
	}

	cout << (dp[SCV[1]][SCV[2]][SCV[3]] - 1);

	return 0;
}


