#include <iostream>

using namespace std;

int L, P, V;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int index = 1;
	while (true)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		int sum = 0;

		int a = V / P; sum += a * L;
		int b = V % P;

		sum += b - L > 0 ? L : b;

		cout << "Case " << index++ << ": " << sum << '\n';

	}
	return 0;
}
