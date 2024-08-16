#include <iostream>
#include <algorithm>

using namespace std;
int lecture[100000];
int N, M;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int end = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> lecture[i];
		end += lecture[i];
	}

	int start = *max_element(lecture, lecture + N);;
	
	int result = 0;

	while (start <= end)
	{
		// mid : 블루레이 한 개당 크기
		int mid = (start + end) / 2;
		int sum = 0;
		int bluerayCount = 0;

		for (int i = 0; i < N; i++)
		{
			if (sum + lecture[i] > mid)
			{
				bluerayCount++;
				sum = 0;
			}
			sum += lecture[i];
		}
		if (sum != 0) bluerayCount++;
		

		// 블루레이 적당함. 크기 조금만 줄여볼까?
		if (M >= bluerayCount)
		{
			end = mid - 1;
		}
		// 예상보다 블루레이가 많이 필요함 -> 개당 크기 늘려야 함
		else
		{
			start = mid + 1;
		}

	}

	cout << start;

	return 0;
}
