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
int dest, fuel;
vector<pair<int, int>> charge;
priority_queue<int> maxHeap;
int main()
{	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int road, fuel;
		cin >> road >> fuel;
		charge.push_back(make_pair(road, fuel));
	}
	cin >> dest >> fuel;
	charge.push_back({ dest, 0 });
	// 내림차순으로 정렬
	sort(charge.begin(), charge.end());

	int cnt = 0;

	for (int i = 0; i <= N; i++)
	{
		// 최대한 갈 수 있을만큼 간다.
		while (charge[i].first > fuel)
		{
			// 더 이상 들릴 주유소가 없다면
			if (maxHeap.empty())
			{
				cout << -1;
				return 0;
			}

			// i번째 주유소에 가기 위한 기름을 충전한다.
			// 충전도, 가장 많은 기름량부터 충전시킨다.
			// 충전했으므로, cnt를 증가시킨다.
			fuel += maxHeap.top();
			maxHeap.pop();
			cnt++;
		}
		maxHeap.push(charge[i].second);
	}

	cout << cnt;


	return 0;
}
