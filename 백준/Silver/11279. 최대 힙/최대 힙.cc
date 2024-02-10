#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> pq;
vector<int> result;
int zero_cnt = 0;

int main()
{	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			zero_cnt++;
			if (pq.empty())
			{
				result.push_back(0);
			}
			else
			{
				int _val = pq.top();
				result.push_back(_val);
				pq.pop();
			}
			continue;
		}

		pq.push(x);
	}

	for (int i = 0; i < zero_cnt; i++)
	{
		cout << result[i] << '\n';
	}

	return 0;
}
