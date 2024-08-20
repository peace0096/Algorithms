#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> s;		// ( : 1, [ : 2
stack<int> values;
string line;
bool visited[30];
bool flag = false;

int recur(int idx)
{
	int result = 0;

	for (int i = idx; i < line.length(); i++)
	{
		if (visited[i]) continue;
		auto c = line[i];
		visited[i] = true;
		if (c == '(')
		{
			
			if (!s.empty() && s.top() == '(')
			{
				s.push(c);
				result += recur(idx + 1);
			}
			else if(!s.empty() && s.top() == '[')
			{
				s.push(c);
				result += recur(idx + 1);
			}
			else
			{
				s.push(c);
			}
			

		}
		else if (c == '[')
		{
			
			if (!s.empty() && s.top() == '(')
			{
				s.push(c);
				result += recur(idx + 1);
			}
			else if (!s.empty() && s.top() == '[')
			{
				s.push(c);
				result += recur(idx + 1);
			}
			else
			{
				s.push(c);
			}
		}
		else if (c == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				flag = true;
				return 0;
			}
			s.pop();
			return result == 0 ? 2 : result * 2;
		}
		else if (c == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				flag = true;
				return 0;
			}
			s.pop();
			return result == 0 ? 3 : result * 3;
		}
	}
	flag = true;
	return 0;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> line;
	s.push(line[0]);
	int result = 0;

	for (int i = 1; i < line.length(); i++)
	{
		if (visited[i]) continue;
		
		int r = recur(i);
		if(flag)
		{
			cout << 0;
			return 0;
		}

		result += r;
	}
	if (s.empty())
	{
		cout << result;
	}
	else
	{
		cout << 0;
	}
	
	return 0;
}
