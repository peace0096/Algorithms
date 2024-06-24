#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	while (true)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0 || y == 0 || z == 0) break;

		int maxV = max(x, max(y, z));
		int minV = min(x, min(y, z));
		int middle = x + y + z - maxV - minV;

		if (maxV < minV + middle)
		{
			if (maxV == minV && minV == middle)
			{
				cout << "Equilateral" << '\n';
				continue;
			}
			else if (minV == middle || maxV == middle)
			{
				cout << "Isosceles " << '\n';
				continue;
			}
			else
			{
				cout << "Scalene " << '\n';
				continue;
			}
		}
		else
		{
			cout << "Invalid" << '\n';
			continue;
		}

		

	}
	

	return 0;
}
