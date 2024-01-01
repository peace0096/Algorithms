#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	map<int, int> _map;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		_map[a]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		cout << _map[a] << " ";
	}
	
}