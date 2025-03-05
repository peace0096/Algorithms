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
vector<int> graph[32001];
int degree[32001];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        degree[B]++;
    }
}


void sol()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();
        cout << now << ' ';
      
        for (auto next : graph[now])
        {
            degree[next]--;

            if (degree[next] == 0)
            {
                pq.push(next);
            }
        }

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

