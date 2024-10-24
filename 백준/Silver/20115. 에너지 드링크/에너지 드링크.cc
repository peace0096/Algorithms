#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<double> drinks;
double now;

int main()
{
	cin >> N;

	
	for (int i = 0; i < N; i++)
	{
		double x;
		cin >> x;
		drinks.push_back(x);
	}

	sort(drinks.begin(), drinks.end());
	now = drinks[N - 1];

	for (int i = 0; i < N - 1; i++)
	{
		now += drinks[i] / 2;
	}

	cout << now;

	return 0;
}


