#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//1 : 1
	//2~7 : 2
	//8~19 : 3
	int N;
	cin >> N;
	int now = 1;
	int count = 0;

	while (true)
	{
		now += (count++) * 6;
		if (N <= now)
		{
			cout << count;
			break;
		}
	}

	return 0;
}
