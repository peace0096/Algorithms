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

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		stack<char> s;
		string line;
		cin >> line;
		bool flag = false;
		
		for (int j = 0; j < line.size(); j++)
		{
			char c = line[j];
			if (c == '(')
			{
				s.push(c);
			}
			else
			{
				if (s.empty())
				{
					flag = true;
					break;
				}
				if (s.top() == '(')
				{
					s.pop();
				}
				else
				{
					flag = true;
					break;
				}
			}
		}

		if (s.empty() && !flag)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}

	}
	
}