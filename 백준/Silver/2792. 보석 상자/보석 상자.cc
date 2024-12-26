#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M;
vector<int> zam;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        zam.push_back(x);
    }

    sort(zam.begin(), zam.end());

    int l = 1;
    int r = zam[M - 1];
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;  // 질투심 가정하기

        int cnt = 0;    // 어린이
        for (int i = 0; i < M; i++)
        {
            cnt += zam[i] / mid;
            if (zam[i] % mid != 0) cnt++;
        }

        if (cnt <= N)   // 어린이 명수 맞음
        {
            r = mid - 1;
            ans = mid;
        }
        else // 질투심 너무 낮음
        {
            l = mid + 1;
        }
    }
    cout << ans;

    return 0;
}

