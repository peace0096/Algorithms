#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	int dirX[4] = { -1, 0, 1, 0 };
	int dirY[4] = { 0, -1, 0, 1 };

	queue<pair<int, int>> q;
	vector<vector<int>> tomatos(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<int>> dists(n, vector<int>(m, 0));

	int max_dist = 0;

	int count = 0;	// 익지 않은 토마토 개수

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomatos[i][j];
			if (tomatos[i][j] == 0) count++;
			else if (tomatos[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = pos.first + dirY[i];
			int newX = pos.second + dirX[i];

			if (newY < 0 || newY >= n ||
				newX < 0 || newX >= m || tomatos[newY][newX] == -1)
				continue;

			if (!visited[newY][newX] && tomatos[newY][newX] == 0)
			{
				visited[newY][newX] = true;
				tomatos[newY][newX] = 1;
				dists[newY][newX] = dists[pos.first][pos.second] + 1;
				max_dist = max(max_dist, dists[newY][newX]);

				q.push(make_pair(newY, newX));
				
				count--;
			}
		}
	}

	if (count == 0)
	{
		cout << max_dist;
	}
	else
	{
		cout << -1;
	}




	return 0;
}