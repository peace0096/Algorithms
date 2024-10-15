#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

char cave[101][101];
int R, C;

// 막대기 개수
int NumberOfStick;

int Sticks[101];

// true : 왼쪽에서 오른족, false : 오른쪽에서 왼쪽
bool IsLeft = true;

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

void ThrowStick(int stick)
{
	if (IsLeft)
	{
		for (int i = 0; i < C; i++)
		{
			if (cave[stick][i] == 'x')
			{
				// 미네랄일 경우 부수기
				cave[stick][i] = '.';
				break;
			}
		}
	}
	else
	{
		for (int i = C - 1; i >= 0; i--)
		{
			if (cave[stick][i] == 'x')
			{
				// 미네랄일 경우 부수기
				cave[stick][i] = '.';
				break;
			}
		}
	}
	IsLeft = !IsLeft;
}

void CheckGravity()
{
	bool visited[100][100] = { false, };
	bool IsClusterFall = false;
	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
	{
		if (IsClusterFall) break;
		if (visited[i][j]) continue;
		visited[i][j] = true;

		if (cave[i][j] == 'x')
		{
			// 클러스터 조사
			queue<pair<int, int>> q;
			vector<pair<int, int>> cluster;
			cluster.push_back({ i, j });
			int min_y = i;	// 중력 영향 받는지 체크... 만약 R - 1이라면 중력 적용 X
			q.push({ i, j });


			while (!q.empty())
			{
				int nowY = q.front().first;
				int nowX = q.front().second;
				q.pop();

				for (int d = 0; d < 4; d++)
				{
					int newY = nowY + dirY[d];
					int newX = nowX + dirX[d];

					if (newY < 0 || newY >= R ||
						newX < 0 || newX >= C || visited[newY][newX]) continue;

					visited[newY][newX] = true;
					if (cave[newY][newX] == 'x')
					{
						cluster.push_back({ newY, newX });
						q.push({ newY, newX });
						min_y = max(min_y, newY);
					}
				}
			}

			if (min_y < R - 1)
			{
				// 중력 적용해야 함
				IsClusterFall = true;
				bool StopGravity = false;

				sort(cluster.begin(), cluster.end(), compare);
				
				// 클러스터의 바로 아랫부분이 바닥인가?
				while ( !StopGravity)
				{
					for (int k = 0; k < cluster.size(); k++)
					{
						int nowY = cluster[k].first;
						int nowX = cluster[k].second;

						cave[nowY + 1][nowX] = 'x';
						cave[nowY][nowX] = '.';
						min_y = max(nowY + 1, min_y);

						cluster[k].first = nowY + 1;

						if (nowY + 2 == R)
						{
							// 바닥 확인
							StopGravity = true;
						}
						else if (!StopGravity && cave[nowY + 2][nowX] == 'x')
						{
							// 아래 미네랄 있는지 확인
							// but, 같은 클러스터 미네랄인지 확인

							bool flag = true;
							for (int p = 0; p < cluster.size(); p++)
							{
								if (cluster[p].first == nowY + 2 && cluster[p].second == nowX)
								{
									flag = false;
									break;
								}
							}

							StopGravity = flag;
						}

					}
				}

				

			}
			



		}


	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
	{
		cin >> cave[i][j];
	}

	cin >> NumberOfStick;

	for (int i = 0; i < NumberOfStick; i++)
	{
		cin >> Sticks[i];
	}
	
	for (int i = 0; i < NumberOfStick; i++)
	{
		ThrowStick(R - Sticks[i]);
		CheckGravity();
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << cave[i][j];
		}
		if (i == R - 1) continue;
		cout << '\n';
	}
	

	return 0;
}


