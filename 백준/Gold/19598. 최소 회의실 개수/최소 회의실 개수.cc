#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
pair<int, int> meeting[100000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		meeting[i] = { start, end };
	}
	sort(meeting, meeting + N);

	priority_queue<int, vector<int>, greater<int>> q;
	int cnt = 1;
	q.push(meeting[0].second);

	for (int i = 1; i < N; i++)
	{
		int start = meeting[i].first;
		int end = meeting[i].second;

		int latest_meeting_end = q.top();
		

		if (latest_meeting_end <= start)
		{
			q.pop();
			q.push(end);
		}
		else
		{
			cnt++;
			q.push(end);
			
			
		}

	}
	
	cout << cnt;

	return 0;
}


