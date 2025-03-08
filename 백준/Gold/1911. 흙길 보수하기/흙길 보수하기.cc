#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;

int N, L;
pair<int, int> arr[10000];


void input()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = { a, b };
    }
}


void sol()
{
    sort(arr, arr + N);
    int ans = 0;
    int end_bridge = -1;
    
    for (int i = 0; i < N; i++)
    {
        int start = arr[i].first;
        int end = arr[i].second;

        while (end_bridge < end - 1)
        {
            // 널빤지 필요
            end_bridge = end_bridge >= start ? end_bridge + L : start + L - 1;
            ans++;
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

