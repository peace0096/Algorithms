#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> crain;
vector<int> box;
queue<int> q;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		crain.push_back(x);
	}

	sort(crain.begin(), crain.end(), greater<int>());


	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		box.push_back(x);
		
	}

	sort(box.begin(), box.end(), greater<int>());
	for (int i = 0; i < M; i++)
	{
		q.push(box[i]);
	}

	int minutes = 0;
	while (!q.empty())
	{
		int cnt = q.size();
		minutes++;
		bool used[50] = { false };
		int used_num = 0;
		while (cnt > 0)
		{
			bool flag = false;
			int b = q.front();
			q.pop();

			for (int i = 0; i < crain.size(); i++)
			{
				if (!used[i] && crain[i] >= b)
				{
					// 옮기기 가능
					used[i] = true;
					flag = true;
					used_num++;
					break;
				}
				
			}
			if (!flag)
			{
				q.push(b);
			}
			if (used_num == 0)
			{
				// 한 번도 안 쓰였다면
				cout << -1;
				return 0;
			}

			cnt--;
		}
	}
	
	cout << minutes;

	
	

	return 0;
}


