#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> edge;
int cost[1001][1001];



int main()
{
	cin >> N >> M >> X;
	edge = vector<vector<pair<int, int>>>(N + 1);

	for (int i = 0; i < M; i++)
	{
		int start, end, time;
		cin >> start >> end >> time;
		edge[start].push_back({ end, time });
	}


	for (int j = 1; j <= N; j++)
	{
		queue<int> q;
		q.push(j);
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			

			for (int i = 0; i < edge[node].size(); i++)
			{
				int next = edge[node][i].first;
				int time = edge[node][i].second;
				if (cost[j][next] == 0 && next != j)
				{
					cost[j][next] = cost[j][node] + time;
					q.push(next);
				}
				if (cost[j][next] > cost[j][node] + time)
				{
					// 업데이트 필요
					cost[j][next] = cost[j][node] + time;
					q.push(next);
				}
			}
		}
	}

	

	
	int ans = 0;
	for (int i = 1; i <= N; i++) 
	{
		ans = max(cost[i][X] + cost[X][i], ans);
	}
	cout << ans;
	return 0;
}


