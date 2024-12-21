#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int cond1 = (r1 - r2) * (r1 - r2);
        int cond2 = (r1 + r2) * (r1 + r2);

        if (d == 0)
        {
            // (x1, y1), (x2, y2), r1과 r2가 같을 경우 -> 원주만큼 점이 있으므로 무한대
            if (cond1 == 0)
                cout << -1 << '\n';
            // 닿지 않음
            else
                cout << 0 << '\n';
        }
        // 두 원의 중심 간 거리가 두 원의 반지름의 합과 같을 경우
        else if (d == cond1 || d == cond2)
            cout << 1 << '\n';
        // 그 외의 경우 -> 두 원이 겹침
        else if (d > cond1 && d < cond2)
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
        
    }
    return 0;
}

