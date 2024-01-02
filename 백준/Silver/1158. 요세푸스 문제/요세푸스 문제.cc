#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	cout << '<';
	while (N > 0)
	{
		N--;
		for (int i = 0; i < K-1; i++)
		{
			int x = q.front();
			q.pop();
			q.push(x);
		}
		int y = q.front();
		q.pop();
		cout << y;
		if (N != 0)
			cout << ", ";
	}
	cout << '>';


	return 0;
}

 // 1 4 5 7