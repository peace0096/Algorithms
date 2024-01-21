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

int N;
int arr[21][21];
int _min = 9999999999999;

void BF(bool team[], int index, int count)
{
	if (count == N / 2)
	{

		int team1 = 0;
		int team2 = 0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = i; j <= N; j++)
			{
				if (team[i] && team[j])
				{
					team1 += arr[i][j];
					team1 += arr[j][i];
				}
				else if (!team[i] && !team[j])
				{
					team2 += arr[i][j];
					team2 += arr[j][i];
				}
			}
		}

		_min = min(_min, abs(team1 - team2));
	}
	else
	{
		for (int i = index + 1; i <= N; i++)
		{
			
			bool new_team[21] = { false, };
			for (int j = 1; j <= N; j++)
				new_team[j] = team[j];
			new_team[i] = true;
			BF(new_team, i, count + 1);
		}
	}
}



int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		bool team[21] = { false, };;
		team[i] = true;
		BF(team, i, 1);
	}
	
	cout << _min << '\n';


	return 0;
}
