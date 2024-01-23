#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>
#include <math.h>
using namespace std;

int M, N;
int arr[51][51];

vector<pair<int, int>> house, chicken, picked;
int _min = 987654321;
bool selected[13] = { false, };


void dfs(int x, int m)
{
	if (m == M)
	{
		int result = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int min_dist = 987654321;
			for (int j = 0; j < picked.size(); j++)
			{
				int dis = abs(house[i].first - picked[j].first)
					+ abs(house[i].second - picked[j].second);
				min_dist = min(min_dist, dis);
			}
			result += min_dist;
		}
		_min = min(_min, result);
	}
	

	for (int i = x; i < chicken.size(); i++)
	{
		// 이미 뽑은거면 패스함
		if (selected[i]) continue;

		// 치킨집을 고릅니다.
		selected[i] = true;
		picked.push_back(chicken[i]);
		dfs(i, m + 1); // 순회돕니다.

		// 다른 치킨집을 고르기 위해 해제합니다.
		selected[i] = false;
		picked.pop_back();

	}
}

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int t;
			cin >> t;
			if (t == 1) house.push_back(make_pair(i, j));
			if (t == 2) chicken.push_back(make_pair(i, j));
		}
	}


	dfs(0, 0);
	cout << _min << '\n';
}
