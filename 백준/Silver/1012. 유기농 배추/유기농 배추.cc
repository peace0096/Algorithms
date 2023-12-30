#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int BFS()
{
	int n, m, c;
	vector<vector<int>> arr(50, vector<int>(50, 0));
	vector<vector<bool>> visited(50, vector<bool>(50, false));

	int lava = 0;
	queue<pair<int, int>> q;
	int dirY[4] = { -1, 0, 1, 0 };
	int dirX[4] = { 0, -1, 0, 1 };

	cin >> n >> m >> c;

	for (int i = 0; i < c; i++)
	{
		int y, x;
		cin >> y >> x;
		arr[y][x] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && !visited[i][j])
			{
				q.push(make_pair(i, j));
				visited[i][j] = true;
				lava++;
				while (!q.empty())
				{
					pair<int, int> pos = q.front();
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int newY = pos.first + dirY[k];
						int newX = pos.second + dirX[k];

						if (newY < 0 || newY >= n ||
							newX < 0 || newX >= m || arr[newY][newX] == 0 || visited[newY][newX])
							continue;

						q.push(make_pair(newY, newX));
						visited[newY][newX] = true;

					}
				}
			}
		}
	}
	return lava;
}


int main()
{
	int T;
	cin >> T;
	vector<int> lavas;

	for (int i = 0; i < T; i++)
	{
		lavas.push_back(BFS());
	}

	for (auto l : lavas)
	{
		cout << l << '\n';
	}


	return 0;
}