#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> adj[3001];

int parent[3001];
int visited[3001] = { false, };
bool cycles[3001] = { false, };
bool hasCycle = false;

void dfs(int cur)
{
    visited[cur] = true;
    for (int next : adj[cur])
    {
        if (hasCycle) return;
        if (!visited[next])
        {
            parent[next] = cur;
            dfs(next);
        }
        else if (next != parent[cur])
        {
            cycles[cur] = true;
            hasCycle = true;
            while (cur != next)
            {
                cycles[parent[cur]] = true;
                cur = parent[cur];
            }
        }
    }

}

void bfs(int start)
{
    if (cycles[start])
    {
        cout << 0 << '\n';
        return;
    }
    bool visited1[3001] = { false };
    queue<int> q;
    q.push(start);
    visited1[start] = true;
    
    int depth = 0;
    while (!q.empty())
    {
        int sz = q.size();
        depth++;
        while (sz > 0)
        {
            int now = q.front();
            q.pop();
            sz--;

            for (int next : adj[now])
            {
                if (cycles[next])
                {
                    // 순환 발견
                    cout << depth << '\n';
                    return;
                }

                if (visited1[next])
                {
                    continue;
                }
                visited1[next] = true;
                q.push(next);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    dfs(1);
    for (int i = 1; i <= N; i++) bfs(i);


    
    return 0;
}

