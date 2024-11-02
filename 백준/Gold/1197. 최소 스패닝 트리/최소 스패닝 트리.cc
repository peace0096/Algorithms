#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
vector<pair<int, int>> adj[10001];
bool visited[10001] = { false };
int spanning[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int start, end, edge;
        cin >> start >> end >> edge;
        adj[start].push_back({ edge, end });
        adj[end].push_back({ edge, start });
    }

    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    visited[1] = true;
    int cnt = 0;
    for (auto edge_end : adj[1]) pq.push(edge_end);

    while (cnt < V - 1)
    {
        // 스패닝 트리 -> 모든 정점 최소한의 간선으로.. 따라서, 정점 - 1 만큼 반복 -> 최소 간선 개수!
        pair<int, int> edge_node = pq.top();
        pq.pop();

        // pq -> 최소 가중치를 먼저 방문하기 때문에, 중복되는 간선이 있을 수 있으므로 한번 예외처리
        if (visited[edge_node.second]) continue;
        visited[edge_node.second] = true;
        cnt++;
        ans += edge_node.first;

        for (auto next : adj[edge_node.second])
        {
            // 이미 방문한 곳은 갈 필요 없으니 걸러
            if(!visited[next.second])
                pq.push(next);
        }


    }

    cout << ans;


    
    return 0;
}

