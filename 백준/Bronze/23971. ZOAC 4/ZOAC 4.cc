#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int W, H, N, M;


int main()
{

	// 세로 : N, 가로 : M
	cin >> H >> W >> N >> M;
	int x = 1;
	int x_count = 1;

	while (x + M + 1 <= W) {
		x += M + 1;
		x_count++;
	}

	int y = 1;
	int y_count = 1;

	while (y + N + 1 <= H) {
		y += N + 1;
		y_count++;
	}

	cout << x_count * y_count;

	return 0;
}
