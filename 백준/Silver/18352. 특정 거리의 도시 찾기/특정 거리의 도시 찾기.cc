#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, X;
vector<vector<int>> edge;
vector<int> distances;

void Dikstra(int now)
{
	for (int i = 0; i < edge[now].size(); i++)
	{
		int next = edge[now][i];


		if (distances[next] > distances[now] + 1)
		{
			distances[next] = distances[now] + 1;
		}
		Dikstra(next);
	}
}

int main()
{
	cin >> N >> M >> K >> X;
	edge = vector<vector<int>>(N + 1);
	distances = vector<int>(N + 1);

	for (int i = 1; i <= N; i++)
	{
		distances[i] = 999999999;
	}

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		edge[start].push_back(end);
	}

	distances[X] = 0;
	
	queue<int> q;
	q.push(X);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < edge[now].size(); i++)
		{
			int next = edge[now][i];
			if (distances[next] > distances[now] + 1)
			{
				distances[next] = distances[now] + 1;
				q.push(next);
			}
			
		}
	}




	bool flag = false;
	for (int i = 1; i <= N; i++)
	{
		if (distances[i] == K)
		{
			cout << i << '\n';
			flag = true;
		}
	}
	if (!flag)
		cout << -1;

	return 0;
}


