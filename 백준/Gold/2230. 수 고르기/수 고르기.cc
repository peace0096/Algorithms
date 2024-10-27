#include <iostream>
#include <algorithm>
using namespace std;
int N, M;

int arr[100000];

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int p1 = 0;
    int ans = 0x7fffffff;
    for (int p2 = 0; p2 < N; p2++)
    {
        while (p1 < N && arr[p1] - arr[p2] < M) p1++;
        if (p1 == N) break;
        ans = min(ans, arr[p1] - arr[p2]);
    }

    cout << ans;

    return 0;
}

