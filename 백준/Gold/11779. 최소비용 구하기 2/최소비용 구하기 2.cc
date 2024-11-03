#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int Start, End;
vector<pair<int, int>> bus[1001];
int costs[1001];
int previous[1001];

void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= N; i++) costs[i] = 0xfffffff;
    costs[Start] = 0;
    // 시작점부터 시작
    pq.push({ costs[Start], Start });
    while (!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        if (costs[now.second] != now.first) continue;
        for (auto next : bus[now.second])
        {
            // 다음 도착까지 비용이 이전 비용보다 더 싸다면!
            if (costs[next.second] > costs[now.second] + next.first)
            {
                costs[next.second] = costs[now.second] + next.first;
                previous[next.second] = now.second;
                pq.push({ costs[next.second], next.second });
            }
        }

        
        

    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        bus[start].push_back({ cost, end });
    }
    cin >> Start >> End;
    Dijkstra();
    
    cout << costs[End] << '\n';

    int node = End;
    vector<int> ans;
    while (node != Start)
    {
        ans.push_back(node);
        node = previous[node];

    }
    ans.push_back(node);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    
    for (int a : ans)
    {
        cout << a << ' ';
    }
    
    return 0;
}

