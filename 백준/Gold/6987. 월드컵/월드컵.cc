#include "iostream"
#include <vector>
using namespace std;

int Record[6][3] = { 0, };
int Backtracking[6][3] = { 0, };
vector<pair<int, int>> play;

bool BF(int played)
{
	if (played == 15)
	{
		for (int i = 0; i < 6; i++) for (int j = 0; j < 3; j++)
		{
			if (Backtracking[i][j] != Record[i][j]) return false;
		}
		return true;
	}

	bool result = false;

	int i = play[played].first;
	int j = play[played].second;


	Backtracking[i][0]++; Backtracking[j][2]++;
	result = BF(played + 1);
	if (result) return true;
	Backtracking[i][0]--; Backtracking[j][2]--;

	Backtracking[i][2]++; Backtracking[j][0]++;
	result = BF(played + 1);
	if (result) return true;
	Backtracking[i][2]--; Backtracking[j][0]--;

	Backtracking[i][1]++; Backtracking[j][1]++;
	result = BF(played + 1);
	if (result) return true;
	Backtracking[i][1]--; Backtracking[j][1]--;

	return false;
}


int main()
{
	for (int i = 0; i < 6; i++) for (int j = i + 1; j < 6; j++)
	{
		play.push_back({ i, j });
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				Backtracking[j][k] = 0;
				cin >> Record[j][k];
			}
		}

		bool result = BF(0);
		if (result) cout << "1" << '\n';
		else cout << "0" << '\n';


	}



	return 0;
}


