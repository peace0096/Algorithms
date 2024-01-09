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

int arr[101];
int dp[10001] = { 0, };

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
	}

	// 0 : 1가지
	// 1 : 1가지
	// 2 : 1원으로 1, 0원으로 1
	// 3 : 1원으로 1, 2원으로 , 0원으로 1

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = arr[i]; j <= k; j++)
		{
			dp[j] += dp[j - arr[i]];
		}
	}
	cout << dp[k] << '\n';
	
	
	return 0;
}