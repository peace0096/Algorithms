#include <iostream>
#include <queue>
using namespace std;

int N, M;
int space[50][50];

int dirX[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dirY[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int ans = 0;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
	{
		cin >> space[i][j];
	}

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
	{
		if (space[i][j] == 0)
		{
			// 빈칸 시작.
			int visited[50][50] = { false, };
			queue<pair<int, int>> q;
			q.push({ i, j });
			visited[i][j] = true;
			int depth = 0;
			bool flag = false;

			while (!q.empty())
			{
				int size = q.size();
				depth++;
				while (size-- > 0)
				{
					int nowY = q.front().first;
					int nowX = q.front().second;
					q.pop();
					for (int k = 0; k < 8; k++)
					{
						int newY = nowY + dirY[k];
						int newX = nowX + dirX[k];

						if (newY < 0 || newY >= N ||
							newX < 0 || newX >= M || visited[newY][newX]) continue;

						visited[newY][newX] = true;
						if (space[newY][newX] == 1)
						{
							ans = max(ans, depth);
							flag = true;
							break;
						}
						else
						{
							q.push({ newY, newX });
						}
					}
					if (flag) break;
				}
				if (flag) break;
			}




		}

		

	}

	cout << ans;


	return 0;
}


