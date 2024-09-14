#include <iostream>

using namespace std;
int N;
int DP[1001];
char road[1001];
const int MAX = 1000000;

int dir[3] = { 'B', 'O', 'J' };

int main() 
{
    cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> road[i];
		DP[i] = MAX;
	}


	DP[1] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (road[i] == 'B' && road[j] == 'O')
			{
				DP[j] = min(DP[j], DP[i] + (j - i) * (j - i));
			}
			else if (road[i] == 'O' && road[j] == 'J')
			{
				DP[j] = min(DP[j], DP[i] + (j - i) * (j - i));
			}
			else if (road[i] == 'J' && road[j] == 'B')
			{
				DP[j] = min(DP[j], DP[i] + (j - i) * (j - i));
			}
		}

	}

	if (DP[N] == MAX)
		cout << -1;
	else
		cout << DP[N];


    return 0;
}