#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int county[100000];
int M;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> county[i];
	}
	sort(county, county + N);

	cin >> M;

	int he = county[N - 1];
	int lo = 0;
	int result = 0;

	
	while (lo <= he)
	{
		int mid = (lo + he) / 2;	// 상한액
		int sum = 0;				// 총 액수

		for (int i = 0; i < N; i++)
		{
			sum += min(county[i], mid);
		}

		// 예산 충분함 -> 상한액 높여도 됨
		if (sum <= M)
		{
			result = mid;
			lo = mid + 1;
		}

		// 예산 부족 -> 상한액 낮춰야 함
		else
		{
			he = mid - 1;
		}

	}

	cout << result;


	return 0;
}
