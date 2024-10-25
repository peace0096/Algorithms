#include <iostream>
#include <algorithm>
using namespace std;

long long n;
pair<long long, long long> HA[100000];
long long A[100000];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> HA[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> HA[i].first;
	}

	sort(HA, HA + n);

	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += HA[i].second + HA[i].first * i;
	}
	
	cout << ans;

	return 0;
}


