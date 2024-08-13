#include <iostream>

using namespace std;

int main()
{
	int N;
	int result = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int constructor = N - i;

		int d = constructor;
		int sum = constructor;

		for (int j = 1000000; j > 0; j = j / 10)
		{
			int divide = d / j;
			sum += divide;
			d = d % j;
		}
		if (sum == N)
		{
			result = constructor;
		}
		
	}
	cout << result;
	
}
