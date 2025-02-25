#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
long long arr[100000];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void sol()
{
    long long ans = 0;
    sort(arr, arr + N, greater<long long>());

    int idx = 0;
    while (idx < N)
    {
        // 2 + 1 선택이 가능한 지(3개 선택 가능한 지)
        if (idx + 2 < N)
        {
            ans += arr[idx] + arr[idx + 1];
            idx += 3;
        }
        else
        {
            for (int i = idx; i < idx + 2; i++)
            {
                if (i < N)
                {
                    ans += arr[idx];
                    idx++;
                }

            }
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

