#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int N, M;
vector<int> graph[32001];
int inDegree[32001];

int main()
{
	cin >> N >> M;

	// 전입차수 및 그래프 그리기
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		inDegree[B]++;
	}

	queue<int> q;

	// 차수가 0인 것을 찾아라.
	for (int i = 1; i <= N; i++)
		if (!inDegree[i])
			q.push(i);

	// 차수를 감소시키면서 0인 것들을 큐에 넣어라
	// 모든 노드들을 넣고 큐가 빌 때까지 반복하라
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = 0; i < graph[cur].size(); i++)
		{
			inDegree[graph[cur][i]]--;
			if (!inDegree[graph[cur][i]])
				q.push(graph[cur][i]);
		}

	}

	return 0;
}
