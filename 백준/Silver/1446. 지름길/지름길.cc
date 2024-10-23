#include <iostream>
using namespace std;

struct Highway
{
	int start;
	int end;
	int road;
};

int N, D;
Highway highways[12];

int cost[10001] = { 0, };

int main()
{
	cin >> N >> D;

	for (int i = 0; i < N; i++)
	{
		Highway highway;
		cin >> highway.start >> highway.end >> highway.road;

		highways[i] = highway;

	}

	int now = 0;

	while (now <= D)
	{
		if (cost[now] == 0) cost[now] = now;
		if(now > 0) cost[now] = min(cost[now], cost[now - 1] + 1);
		for (int i = 0; i < N; i++)
		{
			if (highways[i].start == now)
			{
				// 지름길이 있다면, 일단 간다.
				if (cost[highways[i].end] == 0)
				{
					// 초기화 
					cost[highways[i].end] = cost[now] + highways[i].road;
				}
				else
				{
					cost[highways[i].end] = min(cost[highways[i].end], cost[now] + highways[i].road);
				}
				

			}
		}
		now++;
		
		



	}

	cout << cost[D];

	return 0;
}


