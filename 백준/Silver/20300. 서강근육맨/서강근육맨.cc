#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
long long arr[10000];
long long ans = 0;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void sol()
{
    sort(arr, arr + N);

    if (N % 2 == 1)
    {
        ans = arr[N - 1];

        for (int i = 0; i < (N - 1) / 2; i++)
        {
            ans = max(ans, arr[i] + arr[N - 2 - i]);
        }
    }
    else
    {
        for (int i = 0; i < N / 2; i++)
        {
            ans = max(ans, arr[i] + arr[N - 1 - i]);
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();
    
    
    return 0;
}

