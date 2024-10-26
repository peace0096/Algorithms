#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int arr[30][30];

int ans = 0;

void solve(int a, int b, int c)
{
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = arr[i][a];
		temp = max(temp, arr[i][b]);
		temp = max(temp, arr[i][c]);
		result += temp;
	}

	ans = max(ans, result);
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
	{
		cin >> arr[i][j];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			for (int k = j + 1; k < M; k++)
			{
				solve(i, j, k);


			}
		}
	}
		
	cout << ans;
	
	
	return 0;
}


