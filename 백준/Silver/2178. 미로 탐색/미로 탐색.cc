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

	int arr[102][102];
	int dists[102][102];
	bool visited[102][102];
	queue<pair<int, int>> q;

	int dirX[] = {-1, 0, 1, 0};
	int dirY[] = {0, -1, 0, 1};

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = str[j-1] - '0';
			dists[i][j] = 0;
			visited[i][j] = false;
		}
	}

	q.push(make_pair(1, 1));
	dists[1][1] = 1;
	visited[1][1] = true;

	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();

		if (pos.first == n && pos.second == m)
		{
			cout << dists[pos.first][pos.second];
			break;
		}


		for (int i = 0; i < 4; i++)
		{
			int nY = pos.first + dirY[i];
			int nX = pos.second + dirX[i];
			if (nY < 1 || nY > n ||
				nX < 1 || nX > m || arr[nY][nX] == 0)
				continue;

			if (!visited[nY][nX])
			{
				dists[nY][nX] = dists[pos.first][pos.second] + 1;
				visited[nY][nX] = true;
				q.push(make_pair(nY, nX));
			}
		}
	}

	return 0;

}