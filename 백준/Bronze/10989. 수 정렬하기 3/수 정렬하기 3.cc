
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[10001] = { 0, };
	int c;

	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		arr[c]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 1; j <= arr[i]; j++)
		{
			cout << i << '\n';
		}
	}

	return 0;
}