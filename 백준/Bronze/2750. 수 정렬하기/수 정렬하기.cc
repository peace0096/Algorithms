#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
int n;

void quick(int left, int right) {
	int low = left;
	int high = right;
	int pivot = arr[left];

	while (low <= high) {
		while (pivot > arr[low]) {
			low++;
		}
		while (pivot < arr[high]) {
			high--;
		}
		if (low <= high) {
			int temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
			low++;
			high--;
		}
	}
	if (left < high)
		quick(left, high);
	if (low < right)
		quick(low, right);
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quick(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}


	return 0;
}