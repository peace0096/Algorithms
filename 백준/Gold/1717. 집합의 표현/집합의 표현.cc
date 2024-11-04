#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
vector<int> parent(1000001, -1);

// 이 원소의 부모 노드를 찾아라.
// 유니온 by rank -> 최대한 트리의 높이를 초시화 -> 부모가 될 수 있는 노드의 개수를 가능한 줄이도록!
// 경로 압축 -> 지금 x의 부모를 아예 루트 노드로 박아버림.
int find(int x)
{
    if (parent[x] < 0)
        return x;
    return parent[x] = find(parent[x]);
}

// 두 원소를 합쳐야 함.
bool uni(int u, int v)
{
    // 두 노드의 부모를 찾아라.
    u = find(u);
    v = find(v);

    // 부모가 같다면 이미 같은 그룹임
    if (u == v) return false;

    // 부모가 다르다면, 다른 그룹이니까 합쳐야겠지?
    // 일단 랭크 비교를 하자. 높이가 낮은 트리를 부모로 두는 것이 효율적이다.
    // v의 랭크가 더 클 경우 swap(랭크는 음수로 표기한다)
    // 랭크가 같을 경우 하나만 -1
    if(parent[u] > parent[v]) swap(u, v);
    if (parent[u] == parent[v])
        parent[u]--;
    parent[v] = u;
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) uni(a, b);
        if (op == 1)
        {
            if (find(a) == find(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }

    }
    
    return 0;
}

