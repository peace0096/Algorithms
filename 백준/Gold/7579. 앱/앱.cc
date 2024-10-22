#include <iostream>

using namespace std;

int N, M;
int App[101] = { 0, };
int App_Cost[101] = { 0, };

int dp[101][10001];
int sum_cost = 0;

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> App[i];
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> App_Cost[i];
		sum_cost += App_Cost[i];
	}
	
	for (int i = 1; i <= N; i++)
	{
		int mem = App[i];
		int cost = App_Cost[i];

		for (int j = 0; j <= sum_cost; j++)
		{
			if (j >= cost)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost] + App[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);


		}
	}

	for (int i = 0; i <= sum_cost; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i;
			break;
		}
	}

	return 0;
}


