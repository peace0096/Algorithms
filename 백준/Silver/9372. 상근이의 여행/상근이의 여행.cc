#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;

int T, N, M;
vector<int> graph[1001];
bool visited[1001];

void input()
{
    if (T == 0) cin >> T;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    T--;
}


void sol()
{
    // 초기화
    fill(visited + 1, visited + N + 1, false);
    queue<int> q;
    int result = -1;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int now = q.front(); q.pop();
        result++;
        
        for (auto next : graph[now])
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }

    }

    cout << result << '\n';



    if (T > 0)
    {
        input();
        sol();
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

