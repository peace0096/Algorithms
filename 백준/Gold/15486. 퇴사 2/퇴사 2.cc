#include <iostream>
#include <vector>
using namespace std;

int N;
vector< pair<int, int>> tp;
int dp[1500001];

int main() 
{
    cin >> N;
	int result = 0;
	tp.push_back({ 0, 0 });
	for (int i = 1; i <= N; i++)
	{
		int t, p;
		cin >> t >> p;
		tp.push_back({ t, p });
	}
	

	for (int i = 1; i <= N; i++)
	{
		int t = tp[i].first;
		int p = tp[i].second;
		int nextDay = i + t;

		if (nextDay <= N + 1)
		{
			// 오늘부터 일해서 끝나는 날의 dp
			dp[nextDay] = max(dp[nextDay], p + dp[i]);
		}
		if(i + 1 <= N + 1)
		{
			// 오늘 일 안하고 다음날부터 시작할 경우
			dp[i + 1] = max(dp[i + 1], dp[i]);
		}

		// 일을 안하고 넘기는 경우도 생각해야함.

		
	}

	cout << dp[N + 1];

    return 0;
}