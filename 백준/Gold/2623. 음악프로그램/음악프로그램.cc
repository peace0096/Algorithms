#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;

int N, M;
vector<int> graph[1001];
int degree[1001];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int n; cin >> n;
        int x = 0; cin >> x;
        for (int j = 1; j < n; j++)
        {
            int next; cin >> next;
            graph[x].push_back(next);
            degree[next]++;
            x = next;
        }
    }
}


void sol()
{
    bool visited[1001] = { false, };
    queue<int> results;
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0) q.push(i);
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        results.push(now);
        visited[now] = true;

        for (auto next : graph[now])
        {
            degree[next]--;
            if (degree[next] == 0) q.push(next);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i]) cnt++;
        if (cnt > 1)
        {
            cout << 0;
            return;
        }
    }

    while (!results.empty())
    {
        cout << results.front() << '\n';
        results.pop();
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

