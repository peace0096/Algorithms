#include <iostream>
#include <string.h>
using namespace std;

int map[51][51];
int dirX[] = { 0, 1 };
int dirY[] = { 1, 0 };

int getMaxCandy(int y, int x, int candyType, int N)
{
	int yCount = 1;
	int xCount = 1;

	for (int i = 1; i < N; i++)
	{
		if (y - i > 0 && map[y - i][x] == candyType) yCount++;
		else break;
	}

	for (int i = 1; i < N; i++)
	{
		if (y + i < N && map[y + i][x] == candyType) yCount++;
		else break;
	}

	for (int i = 1; i < N; i++)
	{
		if (x - i > 0 && map[y][x - i] == candyType) xCount++;
		else break;
	}

	for (int i = 1; i < N; i++)
	{
		if (x + i < N && map[y][x + i] == candyType) xCount++;
		else break;
	}

	return max(xCount, yCount);

}

int main()
{
	int N;
	scanf("%d", &N);

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;

		for (int j = 0; j < N; j++)
		{
			map[i][j] = line[j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int targetY = i + dirY[k];
				int targetX = j + dirX[k];

				int tempCandy = map[targetY][targetX];
				map[targetY][targetX] = map[i][j];
				map[i][j] = tempCandy;

				// 첫번째 캔디 검증
				for (int h = 0; h < N; h++)
				{
					for (int g = 0; g < N; g++)
					{
						int getCount = getMaxCandy(h, g, map[h][g], N);
						count = max(count, getCount);
					}
				}

				tempCandy = map[targetY][targetX];
				map[targetY][targetX] = map[i][j];
				map[i][j] = tempCandy;
			}
		}
	}

	printf("%d", count);
	return 0;
	
}
