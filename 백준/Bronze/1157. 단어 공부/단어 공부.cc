#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int arr[26];

int main()
{
	string s;
	cin >> s;

	// a : 97
	// z : 122
	// A : 65
	// Z : 90

	for (char c : s)
	{
		int idx = (c - 97) >= 0 ? c - 97 : c - 65;
		arr[idx]++;
	}

	bool dup_flag = false;
	int MAX = arr[0];
	int max_idx = 0;

	for (int i = 1; i < 26; i++)
	{
		if (MAX < arr[i])
		{
			MAX = arr[i];
			dup_flag = false;
			max_idx = i;
		}
		else if (MAX == arr[i])
		{
			dup_flag = true;
		}
	}

	if (dup_flag) cout << '?';
	else cout << (char)(max_idx + 65);
	
	return 0;
}
