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

int arr[14];
int n;

void DFS(string s, int index, int count)
{
	for (int i = index + 1; i <= n - 5 + count; i++)
	{
		if (count == 5)
		{
			
			cout << s + " " + to_string(arr[i]) << '\n';
		}
		else
		{
			DFS(s + " " + to_string(arr[i]), i, count + 1);
		}
	}

}

int main()
{
	while (true)
	{
		
		cin >> n;
		if (n == 0) return 0;

		
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i <= n - 5; i++)
		{
			string s = to_string(arr[i]);
			DFS(s, i, 1);
		}
		cout << '\n';
	}
	
	

	return 0;
}
