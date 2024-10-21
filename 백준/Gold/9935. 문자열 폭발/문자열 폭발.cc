#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

string line;
string bomb_str;

int main()
{
	cin >> line;
	cin >> bomb_str;

	stack<char> temp;
	int i = 0;

	while (i < line.size())
	{
		if (line.substr(i, bomb_str.size()) == bomb_str)
		{
			// bomb!
			for (int j = 0; j < bomb_str.size(); j++)
			{
				if (!temp.empty())
				{
					char c = temp.top();
					temp.pop();
					line[i + bomb_str.size() - 1 - j] = c;
				}
				else
				{
					i = i + bomb_str.size() - 1 - j + 1;
					break;
				}
			}
			
		}
		else
		{
			// 폭파 안되면 스택에 넣기
			temp.push(line[i]);
			i++;
		}
	}

	stack<char> temp2;

	while (!temp.empty())
	{
		char c = temp.top();
		temp2.push(c);
		temp.pop();
	}

	if (temp2.empty())
	{
		cout << "FRULA";
	}
	else
	{
		while (!temp2.empty())
		{
			cout << temp2.top();
			temp2.pop();
		}
	}

	return 0;
}


