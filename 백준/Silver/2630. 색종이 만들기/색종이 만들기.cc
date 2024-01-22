#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>
#include <math.h>
using namespace std;

int N;
int arr[129][129];
int count_blue = 0;
int count_white = 0;
int pos_x[2] = { 0, 1 };
int pos_y[2] = { 0, 1 };

void Recursive(int y, int x, int n)
{
	if (n == 1)
	{
		arr[y][x] == 1 ? count_blue++ : count_white++;
		return;
	}

	int color = arr[y][x];
	int flag = true;
	for (int i = y; i <= y + n - 1; i++)
	{
		if (!flag) break;
		for (int j = x; j <= x + n - 1; j++)
		{
			// 종이 접어야 함
			if (arr[i][j] != color)
			{
				Recursive(y, x, n / 2);
				Recursive(y + n / 2, x, n / 2);
				Recursive(y, x + n / 2 , n / 2);
				Recursive(y + n / 2, x + n / 2, n / 2);
				flag = false;
				break;
			}
		}
	}
	if (flag) color == 1 ? count_blue++ : count_white++;
}


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	Recursive(1, 1, N);

	cout << count_white << '\n' << count_blue;
}
