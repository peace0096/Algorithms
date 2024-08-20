#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int arr[100];
vector<int> multitap;
int result = 0;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < K; i++)
	{
		if (multitap.size() < N && find(multitap.begin(), multitap.end(), arr[i]) == multitap.end())
		{
			multitap.push_back(arr[i]);
		}
	}

	for (int i = 0; i < K; i++)
	{
		// 사용할 전자제품
		int target = arr[i];

		// 이미 꽂혀져 있으면 패스
		if (find(multitap.begin(), multitap.end(), target) != multitap.end()) continue;
		// 바꿔야 한다면
		else
		{
			int last_idx = -1;
			int last = 0;
			for (int p = 0; p < N; p++)
			{
				int idx = -1;
				for (int k = i + 1; k < K; k++)
				{
					if (multitap[p] == arr[k])
					{
						idx = k;
						break;
					}
				}
				// 더 이상 안 쓰임
				if (idx == -1)
				{
					last_idx = -1;
					last = multitap[p];
					break;
				}
				else
				{
					last_idx = max(last_idx, idx);
					last = arr[last_idx];
				}
			}
			auto rmv = find(multitap.begin(), multitap.end(), last);
			multitap.erase(rmv, rmv + 1);
			multitap.push_back(target);

			result++;
		}
	}
	cout << result;
	
	
	return 0;
}
