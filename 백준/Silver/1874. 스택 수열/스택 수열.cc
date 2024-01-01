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
	int n;
	cin >> n;

	int cur = 1;
	stack<int> s;
	vector<char> vec;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (s.empty())
		{
			int count = x - cur + 1;
			for (int j = 0; j < count; j++)
			{
				s.push(cur++);
				vec.push_back('+');
			}
			s.pop();
			vec.push_back('-');
		}
		else if (s.top() < x)
		{
			int count = x - cur + 1;
			for (int j = 0; j < count; j++)
			{
				s.push(cur++);
				vec.push_back('+');
			}
			s.pop();
			vec.push_back('-');
		}
		else if (s.top() == x)
		{
			s.pop();
			vec.push_back('-');
		}
		else
		{
			cout << "NO" << '\n';
			return 0;
		}
	}
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << '\n';
	}
	return 0;
}