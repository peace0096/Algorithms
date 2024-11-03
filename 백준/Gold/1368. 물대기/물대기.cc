#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> rice_paddy[100002];
bool visited[100002] = { false, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        // 우물을 하나의 정점으로 본다..
        // N개의 입력은 i번째 논이 우물(N+1 정점)로 가는 비용..
        int cost;
        cin >> cost;
        rice_paddy[i].push_back({ cost, N + 1 });
        rice_paddy[N + 1].push_back({ cost, i });
    }

    for(int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;
            rice_paddy[i].push_back({ x, j });
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    visited[1] = true;
    for (auto next : rice_paddy[1])
    {
        if (next.first == 0) continue;
        pq.push(next);
    }
    int cnt = 0;
    int ans = 0;

    while (cnt < N)
    {
        auto now = pq.top();
        pq.pop();

        if (visited[now.second]) continue;
        visited[now.second] = true;
        ans += now.first;

        for (auto next : rice_paddy[now.second])
        {
            if (!visited[next.second]) pq.push(next);
        }
        cnt++;
    }

    cout << ans;
    

    
    return 0;
}

