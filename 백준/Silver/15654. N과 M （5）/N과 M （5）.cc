#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M;
int arr[10];

bool bt[10] = { false, };
int ans[10];

void BackTracking(int n)
{
    if (n == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (bt[i]) continue;
        ans[n] = arr[i];
        bt[i] = true;
        BackTracking(n + 1);
        bt[i] = false;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    BackTracking(0);
    

    return 0;
}

