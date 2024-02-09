#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
vector<vector<int>> cheeze;

int main()
{	
	cin >> M >> N;
	int cheeze_cnt = 0;
	int hour = 0;
	vector<int> disapeare_per_hour;
	int dirX[4] = { -1, 0, 1, 0 };
	int dirY[4] = { 0, -1, 0, 1 };

	vector<int> dis_cheeze_cnt;

	// Make Cheeze
	for (int i = 0; i < M; i++)
	{
		vector<int> rows;
		for (int j = 0; j < N; j++)
		{
			int x;
			cin >> x;
			rows.push_back(x);
			if (x == 1) cheeze_cnt++;
		}
		cheeze.push_back(rows);
	}

	while (true)
	{
		vector<vector<bool>> visited(M, vector<bool>(N, false));
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		int now_disapear_cnt = 0;
		hour++;

		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int newY = y + dirY[i];
				int newX = x + dirX[i];

				if (newY < 0 || newY > M - 1 ||
					newX < 0 || newX > N - 1 ||
					visited[newY][newX]) continue;

				if (cheeze[newY][newX] == 1)
				{
					now_disapear_cnt++;
					cheeze[newY][newX] = 0;
					visited[newY][newX] = true;
				}
				else
				{
					q.push({ newY, newX });
					visited[newY][newX] = true;
				}
			}
		}

		// 1시간 지났음
		cheeze_cnt -= now_disapear_cnt;
		if (cheeze_cnt == 0)
		{
			cout << hour << '\n';
			cout << now_disapear_cnt << '\n';
			return 0;
		}
		disapeare_per_hour.push_back(now_disapear_cnt);

	}
	




	return 0;
}
