#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int children[300000];
int arr[300000];

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> children[i];
	}
	
	sort(children, children + N);

	for (int i = 1; i < N; i++)
	{
		arr[i - 1] = children[i] - children[i - 1];
	}
	
	sort(arr, arr + N - 1);

	int ans = 0;
	for (int i = 0; i < N - K; i++)
	{
		ans += arr[i];
	}

	cout << ans;

	return 0;
}


