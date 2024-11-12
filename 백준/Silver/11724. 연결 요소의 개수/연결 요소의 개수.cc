#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[1001];
bool visited[1001] = { false, };
int cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            // bfs 시작
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int now = q.front();
                q.pop();
                for (auto next : graph[now])
                {
                    if (!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            cnt++;
        }
    }
    cout << cnt;
    

    return 0;
}

