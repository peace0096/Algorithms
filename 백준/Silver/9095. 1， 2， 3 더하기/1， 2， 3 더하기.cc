#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int cached[1000000];

int dp(int n)
{
	cached[1] = 1;
	cached[2] = 2;
	cached[3] = 4;

	for (int i = 4; i <= n; i++)
	{
		cached[i] = cached[i - 1] + cached[i - 2] + cached[i - 3];
	}

	return cached[n];
}

int main()
{
	int T;
	int n;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		cout << dp(n) << '\n';
	}
		
}

// 1 2 3 7 