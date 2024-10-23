#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a, b;
int N, M;

vector<vector<int>> vec;
int cost[1001] = { 0, };

int main()
{
	cin >> a >> b;
	cin >> N >> M;

	vec = vector<vector<int>>(N + 1);

	for (int i = 1; i <= M; i++)
	{
		int start, end;
		cin >> start >> end;
		vec[start].push_back(end);
		vec[end].push_back(start);
	}

	for (int i = 1; i <= N; i++) cost[i] = 10000000;

	queue<int> q;
	q.push(a);
	cost[a] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i];

			if (cost[next] > cost[now] + 1)
			{
				cost[next] = cost[now] + 1;
				q.push(next);
			}
		}


	}
	
	if (cost[b] == 10000000)
	{
		cout << -1;
	}
	else cout << cost[b];


	return 0;
}


