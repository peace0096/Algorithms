#include <iostream>
#include <queue>
using namespace std;

int N, K;

bool visited[100001];
int cost[100001];
queue<int> q;
int depth = 0;
int min_cost = 1000000;

void Go(int now, int next, bool isTeleport)
{
	if (!visited[next])
	{
		visited[next] = true;
		if (isTeleport)
		{
			cost[next] = cost[now];
		}
		else
		{
			cost[next] = cost[now] + 1;
		}
		
		q.push(next);
	}
	else
	{
		// 이미 방문했지만, 더 낮은 코스트라면 다시 해줘야 함.
		if (isTeleport)
		{
			if (cost[next] > cost[now])
			{
				cost[next] = cost[now];
				q.push(next);
			}
		}
		else
		{
			if (cost[next] > cost[now] + 1)
			{
				cost[next] = cost[now] + 1;
				q.push(next);
			}
		}
	}

	if (next == K)
	{
		min_cost = cost[next];
	}
}

int main()
{
	cin >> N >> K;

	q.push(N);
	visited[N] = true;
	cost[N] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (min_cost < cost[now]) continue;

		int next_left = now - 1;
		int next_right = now + 1;
		int next_teleport = now * 2;

		if (next_left >= 0)
		{
			Go(now, next_left, false);
		}
		if (next_right <= 100000)
		{
			Go(now, next_right, false);
		}
		if (next_teleport >= 0 && next_teleport <= 100000)
		{
			Go(now, next_teleport, true);
		}
	}
	
	cout << cost[K];

	return 0;
}


