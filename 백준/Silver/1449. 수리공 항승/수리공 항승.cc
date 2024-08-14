#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int arr[1001];
bool visited[1001] = { false, };
int tapeCount = 0;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	
	for (int i = 0; i < N; i++)
	{
		int loc;
		cin >> loc;
		arr[i] = loc;
	}
	sort(arr, arr + N);
	
	int start = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (L <= arr[i] - start)
		{
			tapeCount++;
			start = arr[i];
		}
	}
	cout << tapeCount + 1;


	return 0;
}
