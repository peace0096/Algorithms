#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

int main()
{	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ y, x });
	}

	sort(v.begin(), v.end());

	int count = 1;
	int end = v[0].first;

	for (int i = 1; i < N; i++)
	{
		if (v[i].second >= end)
		{
			count++;
			end = v[i].first;
		}
	}

	cout << count;
}
