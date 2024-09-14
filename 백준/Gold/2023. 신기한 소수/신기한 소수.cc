#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int prime[4] = { 2, 3, 5, 7 };
int almost_prime[5] = { 1, 3, 5, 7, 9 };
priority_queue<int, vector<int>, greater<int> > pq;

void DFS(int num, int n)
{
	if (n == N)
	{
		pq.push(num);
	}
	for (int i = 0; i < 5; i++)
	{
		bool isPrime = true;
		int result = almost_prime[i] + num * 10;
		for (int i = 2; i < result; i++)
		{
			if (result % i == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			DFS(result, n + 1);
		}
	}

}

int main() 
{
	cin >> N;

	for (int i = 0; i < 4; i++)
	{
		DFS(prime[i], 1);
	}

	while (!pq.empty())
	{
		int i = pq.top();
		cout << i << '\n';
		pq.pop();
	}

	

    return 0;
}