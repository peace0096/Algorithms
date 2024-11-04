#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
vector<int> parent(1000001, -1);

int find(int x)
{
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (parent[v] < parent[u]) swap(u, v);
    if (parent[v] == parent[u]) parent[u]--;
    parent[v] = u;
    return true;
}

int T;
int n, k, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Scenario " << (i + 1) << ":\n";
        cin >> n >> k;
        fill(parent.begin(), parent.begin() + n + 1, -1);
        for (int j = 0; j < k; j++)
        {
            int a, b;
            cin >> a >> b;
            uni(a, b);
        }
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b)) cout << "1\n";
            else cout << "0\n";
        }
        cout << '\n';
    }
    
    
    return 0;
}

