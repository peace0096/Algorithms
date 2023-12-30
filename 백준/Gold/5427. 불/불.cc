#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int BFS()
{
	// 0 : 벽
	// 1 : 길
	// -1 : 불

	int n, m;
	
	cin >> m >> n;

	vector<vector<int>> miro(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<int>> dists(n, vector<int>(m, 1000000));
	vector<vector<bool>> fired(n, vector<bool>(m, false));

	queue<pair<int, pair<int, int>>> q;

	vector<pair<int, int>> fire;
	pair<int, int> sanguen;
	
	int dirY[4] = { -1, 0, 1, 0 };
	int dirX[4] = { 0, -1, 0, 1 };

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < m; j++)
		{
			if (line[j] == '.') miro[i][j] = 1;
			else if (line[j] == '*')
			{
				miro[i][j] = -1;
				fire.push_back(make_pair(i, j));
				fired[i][j] = true;
			}
			else if (line[j] == '@')
			{
				miro[i][j] = 1;
				sanguen = make_pair(i, j);
			}
		}
	}

	q.push(make_pair(1, sanguen));
	dists[sanguen.first][sanguen.second] = 0;
	for (auto f : fire)
	{
		q.push(make_pair(-1, f));
		
	}
	
	while (!q.empty())
	{
		int _type = q.front().first;
		pair<int, int> pos = q.front().second;
		q.pop();

		if (fired[pos.first][pos.second] && _type == 1)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int newY = pos.first + dirY[i];
			int newX = pos.second + dirX[i];

			// 상근이
			if (_type == 1)
			{
				if (newY < 0 || newY >= n ||
					newX < 0 || newX >= m)
				{
					return dists[pos.first][pos.second] + 1;
				}

				if (miro[newY][newX] == -1 || miro[newY][newX] == 0)
					continue;

				if (!visited[newY][newX] && !fired[newY][newX])
				{
					q.push(make_pair(1, make_pair(newY, newX)));
					visited[newY][newX] = true;
					dists[newY][newX] = dists[pos.first][pos.second] + 1;
				}
			}

			//불
			if(_type == -1)
			{
				if (newY < 0 || newY >= n ||
					newX < 0 || newX >= m || miro[newY][newX] == 0)
					continue;

				if (!fired[newY][newX])
				{
					q.push(make_pair(-1, make_pair(newY, newX)));
					fired[newY][newX] = true;
				}
			}

			
		}


	}
	return -1;
}

int main()
{
	int T;
	cin >> T;
	vector<int> result;

	for (int i = 0; i < T; i++)
	{
		result.push_back(BFS());
	}

	for (auto r : result)
	{
		if (r == -1) cout << "IMPOSSIBLE" << '\n';
		else cout << r << '\n';
	}

	return 0;
}