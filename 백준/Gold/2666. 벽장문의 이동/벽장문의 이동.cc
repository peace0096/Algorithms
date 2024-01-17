#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>
using namespace std;

int arr[21] = { 0, };
int dp[21][21][21] = {0,};
int N;
int T;

int _open(int open1, int open2, int index)
{
	if (index == T+1)
		return 0;
	int& ret = dp[open1][open2][index];

	ret = 0;
	ret = min(abs(arr[index] - open1) + _open(arr[index], open2, index + 1),
		abs(arr[index] - open2) + _open(open1, arr[index], index + 1));
	return ret;
}

int main()
{
	
	cin >> N;
	
	int open_a, open_b;
	cin >> open_a >> open_b;

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
	}
	
	cout << _open(open_a, open_b, 1);
	

	return 0;
}
