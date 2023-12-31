#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int arr[100001];
	int dp[100001];

	cin >> arr[1];
	dp[1] = arr[1];

	for (int i = 2; i <= N; i++)
	{
		int a;
		cin >> a;
		arr[i] = a;
		dp[i] = arr[i] + dp[i - 1];
	}

	vector<int> result(M + 1, 0);

	for (int k = 1; k <= M; k++)
	{
		int i, j;
		cin >> i >> j;
		result[k] = dp[j] - dp[i] + arr[i];
	}

	for (int i = 1; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}

	return 0;
}