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

int main()
{	
	cin >> N;

	vector<long> charge(N);
	vector<long> road(N - 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> road[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> charge[i];
	}

	
	long now_charge = charge[0];
	long long result = now_charge * road[0];

	for (int i = 1; i < N - 1; i++)
	{
		if (now_charge <= charge[i])
		{
			// 원래 더 싼 곳에서 기름 구매
			result += now_charge * road[i];
		}
		else
		{
			// 더 싼 곳이 나타났으니 여기서 기름 구매 시작
			result += charge[i] * road[i];
			now_charge = charge[i];
		}

	}

	cout << result;




	return 0;
}
