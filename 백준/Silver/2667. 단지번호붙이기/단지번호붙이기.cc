#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>
#include <math.h>
using namespace std;

int _map[26][26];
int visited[26][26] = { 0, };
int groups[26];
int group_count = 0;
int N;
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < N; j++)
		{
			_map[i][j + 1] = line[j] - '0';
		}
	}
	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// 첫 방문
			if (_map[i][j] == 1 && visited[i][j] == 0)
			{
				queue<pair<int, int>> q;
				group_count++;
				groups[group_count] = 1;
				q.push(make_pair(i, j));
				visited[i][j] = 1;

				while (!q.empty())
				{
					pair<int, int> pos = q.front();
					q.pop();
					int y = pos.first;
					int x = pos.second;

					for (int i = 0; i < 4; i++)
					{
						int newY = y + dirY[i];
						int newX = x + dirX[i];

						if (newY < 1 || newY > N ||
							newX < 1 || newX > N ||
							_map[newY][newX] == 0 ||
							visited[newY][newX] == 1
							)
							continue;

						q.push(make_pair(newY, newX));
						visited[newY][newX] = 1;
						groups[group_count]++;
					}
				}
			}
		}
	}

	cout << group_count << '\n';

	sort(groups + 1, groups + 1 + group_count);
	for (int i = 1; i <= group_count; i++)
	{
		cout << groups[i] << '\n';
	}

	return 0;
}
