#include <iostream>

using namespace std;

int N;
bool arr[21] = { false, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		string op; int x;
		cin >> op;
		
		if (op == "add")
		{
			cin >> x;
			arr[x] = true;
		}
		else if (op == "remove")
		{
			cin >> x;
			arr[x] = false;
		}
		else if (op == "check")
		{
			cin >> x;
			if (arr[x]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (op == "toggle")
		{
			cin >> x;
			arr[x] = !arr[x];
		}
		else if (op == "all")
		{
			for (int j = 1; j <= 20; j++) arr[j] = true;
		}
		else if (op == "empty")
		{
			for (int j = 1; j <= 20; j++) arr[j] = false;
		}
		
	}
	
	return 0;
}
