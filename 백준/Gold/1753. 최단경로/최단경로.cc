#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
int start;
vector<vector<pair<int, int>>> edge;
int cost[200001];

int main()
{
	cin >> V >> E;
	cin >> start;

	edge = vector <vector<pair<int, int>>>(V + 1);

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		// first : node, second : weight
		edge[u].push_back({ v, w });

	}
	
	for (int i = 1; i <= V; i++)
	{
		cost[i] = 1000000;
	}

	priority_queue<pair<int, int>> pq;
	cost[start] = 0;
	pq.push({ 0, start });
	
	while (!pq.empty())
	{
		int now = pq.top().second;
		int now_cost = -pq.top().first;

		pq.pop();

		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i].first;
			if (cost[next] > edge[now][i].second + now_cost)
			{
				// 비용 갱신
				cost[next] = edge[now][i].second + now_cost;
				pq.push({ -cost[next], next });
			}
		}

	}

	for (int i = 1; i <= V; i++)
	{
		if (cost[i] != 1000000) cout << cost[i];
		else cout << "INF";
		cout << '\n';
	}

	return 0;
}


