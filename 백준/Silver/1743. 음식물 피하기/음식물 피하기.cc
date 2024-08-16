#include <iostream>
#include <algorithm>

using namespace std;

int N, M, Trash;
int map[101][101] = { 0, };
bool visited[101][101] = { false, };

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, -1, 0, 1};
int result = 0;

int FindTrash(int y, int x)
{
	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		int newY = y + dirY[i];
		int newX = x + dirX[i];

		if (newY < 1 || newY > N ||
			newX < 1 || newX > M || visited[newY][newX]) continue;

		visited[newY][newX] = true;
		if (map[newY][newX] == 1)
		{
			cnt += FindTrash(newY, newX);
		}
	}
	return cnt;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> Trash;

	for (int i = 0; i < Trash; i++)
	{
		int x, y;
		cin >> y >> x;
		map[y][x] = 1;	// trash
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (visited[i][j]) continue;
			visited[i][j] = true;
			// 쓰레기 발견하면
			if (map[i][j] == 1)
			{
				int count = FindTrash(i, j);
				result = max(result, count);
			}

		}
	}

	cout << result;
	

	return 0;
}
