#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int cached[1000001];

int recursive(int n)
{
	if (n == 1)
		return 0;

	int& ret = cached[n];

	if (ret != -1)
	{
		return ret;
	}

	if (n % 6 == 0)
	{
		int per3 = recursive(n / 3);
		int per2 = recursive(n / 2);
		int minus = recursive(n - 1);
		if (per3 >= per2)
			return ret = min(per2, minus) + 1;
		else if (per3 >= minus)
			return ret = min(minus, per2) + 1;
		else
			return ret = min(per2, per3) + 1;
	}
	else if (n % 3 == 0)
	{
		return ret = min(recursive(n / 3), recursive(n - 1)) + 1;
	}
	else if (n % 2 == 0)
	{
		return ret = min(recursive(n / 2), recursive(n - 1)) + 1;
	}
	else
	{
		return ret = recursive(n - 1) + 1;
	}
}

int main()
{
	int n;
	memset(cached, -1, sizeof(cached));
	cin >> n;
	cout << recursive(n);

	return 0;
}