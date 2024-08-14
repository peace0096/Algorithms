#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int S, T;
		cin >> S >> T;
		vec.push_back(make_pair(S, T));
	}
	sort(vec.begin(), vec.end());

	pq.push(vec[0].second);
	for (int i = 1; i < vec.size(); i++)
	{
		// 시간이 겹치지 않았을 경우, 끝난 시간 교체
		if (vec[i].first >= pq.top())
		{
			pq.pop();
			pq.push(vec[i].second);
		}
		// 시간이 겹쳤다면, 새로우 강의 추가
		else
		{
			pq.push(vec[i].second);
		}
	}
	cout << pq.size();
	return 0;
}
