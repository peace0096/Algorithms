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

int M, N;
int arr[1000001] = { 0, };

int main()
{
	cin >> M >> N;

	for (int i = 2; i <= N; i++)
	{
		arr[i] = i;
	}

	// n의 배수 지우기 시작
	for (int i = 2; i * i <= N; i++)
	{
		// 이미 거쳐간 배수는 패스한다.
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= N; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (arr[i] != 0)
			cout << arr[i] << '\n';
	}

	return 0;
}
