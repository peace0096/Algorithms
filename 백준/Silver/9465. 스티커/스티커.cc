#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
int arr[3][100001] = { 0, };
int dp[3][100001]{ 0, };

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		for (int i = 1; i <= 2; i++)
		{
			for (int n = 1; n <= N; n++)
			{
				int x;
				cin >> x;
				arr[i][n] = x;
			}
		}

		// 1: 50
		// 2: 50 50
		// 3: 50 50 100
		// 4: 50 50 100 10
		// 5: 50 50 100 60
		
		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];
		dp[1][2] = arr[2][1] + arr[1][2];
		dp[2][2] = arr[1][1] + arr[2][2];

		for (int i = 3; i <= N; i++)
		{
			dp[1][i] = arr[1][i] + max(dp[2][i - 1], dp[2][i - 2]);
			dp[2][i] = arr[2][i] + max(dp[1][i - 1], dp[1][i - 2]);
		}

		cout << max(dp[1][N], dp[2][N]) << '\n';


	}
	
	return 0;
}