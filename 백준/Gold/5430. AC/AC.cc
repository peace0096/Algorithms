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

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string instruction;
		int n;
		string arr_str;
		

		cin >> instruction;
		cin >> n;
		cin >> arr_str;
		string subs = arr_str.substr(1, arr_str.size() - 2);
		istringstream ss(subs);
		string buffer;
		bool isFront = true;
		bool isError = false;
		string answer = "";

		deque<string> q;

		while (getline(ss, buffer, ','))
		{
			q.push_back(buffer);
		}
		answer += '[';
		for (int i = 0; i < instruction.size(); i++)
		{
			char c = instruction[i];

			if (c == 'R')
			{
				isFront = !isFront;
			}
			else if(c == 'D')
			{
				if (q.empty())
				{
					cout << "error" << '\n';
					isError = true;
					break;
				}
				if (isFront)
				{
					q.pop_front();
				}
				else
				{
					q.pop_back();
				}
				
			}
		}

		if (!isError)
		{
			cout << '[';
			int _size = q.size();
			for (int i = 0; i < _size; i++)
			{
				if (isFront)
				{
					cout << q.front();
					q.pop_front();
				}
				else
				{
					cout << q.back();
					q.pop_back();
				}
				if (!q.empty()) cout << ',';
			}
			cout << ']' << '\n';
		}
		



	}



	return 0;
}