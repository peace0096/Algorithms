#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> q;

	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	vector<vector<int>> dists(n, vector<int>(m, 1));

	int max_area = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0 || visited[i][j] == 1)
				continue;
			// 새로운 그림 발견
			visited[i][j] = true;
			q.push(make_pair(i, j));
			count++;
			int area = 0;

			while (!q.empty())
			{
				int dirX[] = { -1, 0, 1, 0 };
				int dirY[] = { 0, -1, 0, 1 };

				pair<int, int> pos = q.front();
				q.pop();
				area++;
				
				for (int k = 0; k < 4; k++)
				{
					int newY = pos.first + dirX[k];
					int newX = pos.second + dirY[k];
					if (newY < 0 || newY > n - 1 ||
						newX < 0 || newX > m - 1)
						continue;

					if (arr[newY][newX] == 1 && !visited[newY][newX])
					{
						q.push(make_pair(newY, newX));
						visited[newY][newX] = true;
						
					}
				}

			}
			max_area = max(area, max_area);

		
		}
	}
	
	cout << count << '\n';
	cout << max_area;


}