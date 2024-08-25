#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr[1001];
bool visited_dfs[1001];
bool visited_bfs[1001];
int N, M, V;

void DFS(int n)
{
    cout << n << ' ';
    sort(arr[n].begin(), arr[n].end());
    for (int i = 0; i < arr[n].size(); i++)
    {
        if (visited_dfs[arr[n][i]])
            continue;
        visited_dfs[arr[n][i]] = true;
        DFS(arr[n][i]);
    }
}

void BFS(int n)
{
    queue<int> q;
    visited_bfs[V] = true;
    q.push(n);

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << ' ';
        

        for (int i = 0; i < arr[t].size(); i++)
        {
            if (visited_bfs[arr[t][i]])
                continue;
            visited_bfs[arr[t][i]] = true;
            q.push(arr[t][i]);
        }
    }
}


int main() 
{
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int n, t;
        cin >> n >> t;
        
        arr[n].push_back(t);
        arr[t].push_back(n);
    }

    visited_dfs[V] = true;
    DFS(V);
    cout << '\n';
    BFS(V);
    
    

    return 0;
}