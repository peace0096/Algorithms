#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
long long tree[1000000];

long long mid = 0, r = 0, l = 0;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
	}

	l = 0;
	r = 1000000000;

	while (l + 1 < r)
	{
		long long mid = (r + l) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (tree[i] > mid) sum += tree[i] - mid;
		}
		if (sum >= M)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}

	cout << l;
	
	return 0;
}
