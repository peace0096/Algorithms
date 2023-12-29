#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int R, C;
	int dirY[4] = { -1, 0, 1, 0 };
	int dirX[4] = { 0, -1, 0, 1 };
	cin >> R >> C;

	vector<vector<int>> miro(R, vector<int>(C, 0));
	vector<vector<int>> dists(R, vector<int>(C, 0));
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	vector<vector<bool>> fired(R, vector<bool>(C, false));

	pair<int, pair<int, int>> J;
	vector<pair<int, pair<int, int>>> Fires;

	queue<pair<int, pair<int, int>>> q;

	
	
	for (int i = 0; i < R; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < C; j++)
		{
			if (line[j] == '#') miro[i][j] = 0;
			else if (line[j] == '.') miro[i][j] = 1;
			else if (line[j] == 'J')
			{
				miro[i][j] = 1;
				visited[i][j] = true;
				J = make_pair(1, make_pair(i, j));
			}
			else if (line[j] == 'F')
			{
				miro[i][j] = -1;
				Fires.push_back(make_pair(-1, make_pair(i, j)));
			}
		}
	}
	q.push(J);
	for (auto f : Fires)
	{
		fired[f.second.first][f.second.second] = true;
		q.push(f);

	}
		

	while (!q.empty())
	{
		
		int _type = q.front().first;
		pair<int, int> pos = q.front().second;
		q.pop();

		

		for (int i = 0; i < 4; i++)
		{
			int newY = pos.first + dirY[i];
			int newX = pos.second + dirX[i];

			// 지훈
			if (_type == 1)
			{
				if (fired[pos.first][pos.second]) continue;
				if (newY < 0 || newY >= R ||
					newX < 0 || newX >= C)
				{
					cout << dists[pos.first][pos.second] + 1;
					return 0;
				}
				else if (miro[newY][newX] == 0 ||
					miro[newY][newX] == -1 || fired[newY][newX]) continue;

				if (!visited[newY][newX])
				{
					visited[newY][newX] = true;
					q.push(make_pair(_type, make_pair(newY, newX)));
					dists[newY][newX] = dists[pos.first][pos.second] + 1;
				}
			}
			// 불
			else
			{
				if (newY < 0 || newY >= R ||
					newX < 0 || newX >= C || miro[newY][newX] == 0)
					continue;

				if (!fired[newY][newX])
				{
					q.push(make_pair(_type, make_pair(newY, newX)));
					fired[newY][newX] = true;
				}
			}
		}
	}

	cout << "IMPOSSIBLE ";
	return 0;
}