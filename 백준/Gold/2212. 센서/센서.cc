#include <iostream> 
#include <algorithm>
using namespace std;

int N, K;
int sensor[10000];
int arr[100000];

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> sensor[i];
	}

	sort(sensor, sensor + N);

	for (int i = 1; i < N; i++)
	{
		arr[i - 1] = sensor[i] - sensor[i - 1];
	}

	sort(arr, arr + N - 1);

	int ans = 0;
	for (int i = 0; i < N - (K - 1) - 1; i++)
	{
		ans += arr[i];
	}
	cout << ans;

	return 0;
}


