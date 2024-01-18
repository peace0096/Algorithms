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

struct comp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
		{
			return abs(a) > abs(b);
		}
		
	}
};

int main()
{
	int N;
	cin >> N;
	
	priority_queue<int, vector<int>, comp> pq;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x != 0)
		{
			pq.push(x);
		}
		else
		{
			if (pq.size() == 0)
			{
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
	}
	
	

	return 0;
}
