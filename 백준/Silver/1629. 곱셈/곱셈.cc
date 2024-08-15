#include <iostream>

using namespace std;
long long A, B, C;

long long Calculate(long long b)
{
	if (b == 0) return 1;
	if (b == 1) return A % C;
	if (b == 2) return A * A % C;
	if (b % 2 == 0)
	{
		long long result = Calculate(b / 2);
		return result * result % C;
	}
	if (b % 2 == 1)
	{
		long long result = Calculate(b / 2);
		return result * result % C * A % C;
	}
	
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	long long result = Calculate(B);

	cout << result;
	return 0;
}
