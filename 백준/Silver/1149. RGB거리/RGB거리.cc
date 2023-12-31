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
	int N;
	cin >> N;

	int cost[1001][3];
	int house[1001][3];

	for (int i = 1; i <= N; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		house[i][0] = r;
		house[i][1] = g;
		house[i][2] = b;
	}

	cost[1][0] = house[1][0];
	cost[1][1] = house[1][1];
	cost[1][2] = house[1][2];
	
	for (int i = 2; i <= N; i++)
	{
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + house[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + house[i][1];
		cost[i][2] = min(cost[i - 1][1], cost[i - 1][0]) + house[i][2];
	}

	int result = min(min(cost[N][0], cost[N][1]), cost[N][2]);

	cout << result;

	return 0;
}