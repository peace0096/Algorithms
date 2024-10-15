#include <iostream>
#include <string>
using namespace std;

int T;
string commands;
int x, y;
int dirY;
int dirX;

int min_x;
int min_y;

int max_x;
int max_y;

void UpdateMinMaxLoc()
{
	max_x = max(max_x, x);
	max_y = max(max_y, y);
	min_x = min(min_x, x);
	min_y = min(min_y, y);
}


void Test()
{
	for (int i = 0; i < commands.size(); i++)
	{
		char c = commands[i];
		
		if (c == 'F')
		{
			x += dirX;	y += dirY;
			UpdateMinMaxLoc();

		}
		else if (c == 'B')
		{
			x += dirX * -1;	y += dirY * -1;
			UpdateMinMaxLoc();
		}
		else if (c == 'L')
		{
			if (dirY == 1)
			{
				dirX = -1;
				dirY = 0;
			}
			else if (dirX == -1)
			{
				dirY = -1;
				dirX = 0;
			}
			else if (dirY == -1)
			{
				dirY = 0;
				dirX = 1;
			}
			else if (dirX == 1)
			{
				dirY = 1;
				dirX = 0;
			}
		}
		else if (c == 'R')
		{
			if (dirY == 1)
			{
				dirX = 1;
				dirY = 0;
			}
			else if (dirX == 1)
			{
				dirY = -1;
				dirX = 0;
			}
			else if (dirY == -1)
			{
				dirY = 0;
				dirX = -1;
			}
			else if (dirX == -1)
			{
				dirY = 1;
				dirX = 0;
			}

		}



	}

	int width = max_x - min_x;
	int height = max_y - min_y;
	cout << width * height << '\n';


}


int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> commands;
		x = 0; y = 0;
		dirY = 1;
		dirX = 0;

		min_x = 0;
		min_y = 0;

		max_x = 0;
		max_y = 0;
		Test();
	}

	return 0;
}


