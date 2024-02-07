#include <iostream>
#include <vector>

using namespace std;

int N, K;

vector<int> coins;

int main()
{	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		coins.push_back(x);
	}

	// 내림차순으로 순회 시작
	for (int i = N - 1; i > -1; i--)
	{
		// 가장 가치가 높은 동전부터 최대한 넣기
		if (coins[i] <= K)
		{
			int remain = K;
			int idx = i;
			int mostValuableCoinCount = remain / coins[idx];
			int cnt = 0;
			
			while (true)
			{
				cnt += remain / coins[idx];
				if (remain % coins[idx] == 0)
				{
					cout << cnt;
					return 0;
				}
				remain = remain % coins[idx--];

				// 최대한 우겨 넣어도 남는다면
				if (idx == -1)
				{
					idx = i;
					remain += coins[idx--];
					cnt--;
					mostValuableCoinCount--;
					if (mostValuableCoinCount == 0)
						break;
				}
			}
		}
	}


	return 0;
}
