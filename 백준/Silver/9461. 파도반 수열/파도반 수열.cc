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
long long dp[101];

int main()
{
	int T;
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		for (int i = 6; i <= N; i++)
			dp[i] = dp[i - 1] + dp[i - 5];
		cout << dp[N] << '\n';
	}
	
	return 0;
}

/*
dp[1] = 1
dp[2] = 1
dp[3] = 1
dp[4] = 2
dp[5] = 2
dp[6] = 3 -> 5번과 3번(1)
dp[7] = 4 -> 6번과 2번(1)
dp[8] = 5 -> 7번과 1번(1)
dp[9] = 7 -> 8번과 4번(2)
dp[10] = 9 -> 9번과 5번(2)

*/