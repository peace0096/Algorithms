#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int H, W;
int height[500];
vector<int> water;
stack<int> walls;
stack<int> walls1;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;

	
	for (int i = 0; i < W; i++)
	{
		cin >> height[i];
	}
	int result = 0;
	int latest = height[0];
	int latestIdx = 0;
	for (int i = 1; i < W; i++)
	{
		// 빗물 고인다.
		if (latest > height[i])
		{
			walls.push(height[i]);
		}
		// 새로운 웅덩이
		else if (latest <= height[i])
		{
			int w = ((walls.size()) * latest);
			while (!walls.empty())
			{
				int minus = walls.top();
				walls.pop();
				if (minus == latest) continue;
				
				w -= minus;
			}
			result += w;
			latest = height[i];
			latestIdx = i;
		}

	}
	// 마지막 남은 웅덩이 처리해야 함
	// 위 로직을 거꾸로 해야 함.

	if (!walls.empty())
	{
		int latest1 = height[W - 1];
		
		for (int i = W - 2; i >= latestIdx; i--)
		{
			// 빗물 고인다.
			if (latest1 > height[i])
			{
				walls1.push(height[i]);
			}
			// 새로운 웅덩이
			else if (latest1 <= height[i])
			{
				int w = ((walls1.size()) * latest1);
				while (!walls1.empty())
				{
					int minus = walls1.top();
					walls1.pop();
					if (minus == latest1) continue;

					w -= minus;
				}
				result += w;
				latest1 = height[i];
			}
		}
	}

	cout << result;
	
	return 0;
}
