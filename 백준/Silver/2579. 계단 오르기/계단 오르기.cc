#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int cached[301];	// 최댓값만 저장
int stair[301];		// 계단점수

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int s;
		cin >> s;
		stair[i] = s;
	}

	cached[1] = stair[1];
	cached[2] = stair[1] + stair[2];
	cached[3] = stair[3] + max(stair[1], stair[2]);

	//12 4
	//13 4

	for (int i = 4; i <= N; i++)
	{
		cached[i] = stair[i] + max(cached[i - 3] + stair[i - 1], cached[i - 2]);
	}

	cout << cached[N];
	return 0;
}