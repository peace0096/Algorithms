#include <iostream>

using namespace std;
int N;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	// 2, 4, 6

	int a = N % 4;
	if (a == 0 || a == 2)
		cout << "CY";
	else if (a == 1 || a == 3)
		cout << "SK";


	return 0;
}
