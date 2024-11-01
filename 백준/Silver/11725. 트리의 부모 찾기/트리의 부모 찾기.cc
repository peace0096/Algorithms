#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr[100001];
int parent[1000001];

void dfs(int now)
{
    
    for (int i = 0; i < arr[now].size(); i++)
    {
        int next = arr[now][i];
        if (parent[now] == next) continue;
        parent[next] = now;
        dfs(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start].push_back(end);
        arr[end].push_back(start);
    }

    dfs(1);
    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << '\n';


    }

    
    return 0;
}

