#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string lines[50];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> lines[i];
	}

	sort(lines, lines + N);
	int ans = N;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (lines[j].substr(0, lines[i].size()) == lines[i])
			{
				ans--;
				break;
			}
		}
	}


	cout << ans;
	return 0;
}


