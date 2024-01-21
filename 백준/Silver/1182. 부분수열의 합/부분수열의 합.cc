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

int N, S;
int arr[21];
int _count = 0;

void DFS(int sum, int index)
{
	if (sum == S) _count++;
	for (int i = index + 1; i <= N; i++)
	{
		DFS(sum + arr[i], i);
	}

}


int main()
{
	cin >> N >> S;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		DFS(arr[i], i);
	}

	cout << _count << '\n';


	return 0;
}
