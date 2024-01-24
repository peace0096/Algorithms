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

int N;
int arr[100001];
int dis[100001];

int euc(int a, int b)
{
	int r = a % b;
	if (r == 0)
		return b;
	else
	{
		return euc(b, r);
	}
}

int main()
{
	int count = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 1; i <= N - 1; i++)
	{
		dis[i] = arr[i + 1] - arr[i];
	}

	int gcd = dis[1];
	for (int i = 2; i <= N - 1; i++)
	{
		gcd = euc(gcd, dis[i]);
	}

	for (int i = 1; i <= N - 1; i++)
	{
		count += (dis[i] / gcd) - 1;
	}

	cout << count;


	return 0;
}
