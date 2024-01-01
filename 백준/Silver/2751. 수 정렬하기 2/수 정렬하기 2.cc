#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec;

	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		vec.push_back(c);
	}

	sort(vec.begin(), vec.end());
	
	for (int v : vec)
		cout << v << '\n';
	


	return 0;
}