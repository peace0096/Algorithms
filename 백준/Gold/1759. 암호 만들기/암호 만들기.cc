#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int L, C;
char chars[15];
bool crypt[15];

vector<string> results;

void DFS(int now, int cnt)
{
	if (cnt == L)
	{
		string ans = "";
		int aeiou_cnt = 0;
		int etc_cnt = 0;

		for (int i = 0; i < C; i++)
		{
			if (crypt[i])
			{
				if (chars[i] == 'a' || chars[i] == 'i' || chars[i] == 'o' ||
					chars[i] == 'e' || chars[i] == 'u')
				{
					aeiou_cnt++;
				}
				else
				{
					etc_cnt++;
				}
				ans.push_back(chars[i]);
			}
				
		}

		if (aeiou_cnt >= 1 && etc_cnt >= 2)
		{
			results.push_back(ans);
		}
		
		return;
	}

	for (int i = now + 1; i < C; i++)
	{
		crypt[i] = true;
		DFS(i, cnt + 1);
		crypt[i] = false;
	}

	
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> chars[i];
	}

	sort(chars, chars + C);

	/*for (int i = 0; i < C - L + 1; i++)
	{
		crypt[i] = true;
		DFS(i, 1);
		crypt[i] = false;
	}*/
	
	DFS(-1, 0);
	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i];
		if (i != results.size() - 1) cout << '\n';
	}

	return 0;
}


