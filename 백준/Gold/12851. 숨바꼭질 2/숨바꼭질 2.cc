#include <iostream>
#include <queue>
using namespace std;

int N, K;
int ways = 0;
int visited[100001];
queue<int> q;

void Go(int next, int now)
{
	if (!visited[next] || visited[next] == visited[now] + 1)
	{
		visited[next] = visited[now] + 1;
		q.push(next);
	}
	
	if (K == next)
	{
		ways++;

	}
}

int main()
{
	cin >> N >> K;

	
	q.push(N);

	while (!q.empty())
	{
		int i = q.size();
		while (i-- > 0)
		{
			int now = q.front();
			q.pop();
			if (now == K) continue;

			int walk_left = now - 1;
			int walk_right = now + 1;
			int teleport = now * 2;

			if (walk_left >= 0)
			{
				Go(walk_left, now);
			}
			if (walk_right <= 100000)
			{
				Go(walk_right, now);
			}
			if (teleport <= 100000 && teleport >= 0)
			{
				Go(teleport, now);
			}

		}

		if (ways > 0) break;
	}

	if (N == K) ways++;
	cout << visited[K] << '\n' << ways;


	return 0;
}


