#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;

int N;
int times[10001];
vector<int> graph[10001];
int degree[10001];
int min_time[10001];

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> times[i] >> cnt;

        for (int j = 0; j < cnt; j++)
        {
            int prev;
            cin >> prev;
            graph[prev].push_back(i);
            degree[i]++;
        }

    }
    
}


void sol()
{

    // first : node, second : time
    queue<int> q;
    

    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
            min_time[i] = times[i];
        }
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (auto next : graph[now])
        {
            degree[next]--;
            min_time[next] = max(min_time[next], min_time[now] + times[next]);

            if (degree[next] == 0) q.push(next);
        }
    }

    sort(min_time + 1, min_time + N + 1);
    cout << min_time[N];

}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

