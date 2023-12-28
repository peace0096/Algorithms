#include <iostream>
using namespace std;
bool arr[1000001]; // false면 소수

int main(void) {
    
    int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= 1000000; ++i) {
		if (!arr[i]) {
			for (int j = i+i; j <= 1000000; j += i) {
				if (!arr[j]) {
					arr[j] = true;
				}
			}
		}
	}
	for (int i = 0; i <= 100000; ++i) {
		cin >> n;
		if (n == 0)
            break;

		for (int j = 3; j <= 1000000; j+=2) {
			if (!arr[j] && !arr[n - j]) {
				cout << n << " = " << j << " + " << n - j << "\n";
				break;
			}
		}
	}
}