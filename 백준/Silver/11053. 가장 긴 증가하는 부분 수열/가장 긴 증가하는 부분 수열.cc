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

int arr[1001];
int dp[1001];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
	}
	
	int _max = 0;	// 최장 부분증가 수열 길이
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] <= dp[j])
				dp[i] += 1;
		}
		_max = max(_max, dp[i]);
	}
	cout << _max << '\n';


	return 0;
}
