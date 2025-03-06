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

int parent[100001];

struct cmp
{
    bool operator()(pair<int, pair<int, int>>& p1, pair<int, pair<int, int>>& p2)
    {
        return p1.first > p2.first;
    }
};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        // first : cost, second.first : A, second.second : B

       pq.push({ C, {A, B} });
    }
}

int Find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    int parent_x = Find(x);
    int parent_y = Find(y);
    if (parent_x == parent_y) return;
    parent[parent_x] = parent_y;
}

void sol()
{
    int result = 0;
    int last = 0;
    for (int i = 1; i <= N; i++) parent[i] = i;

    while (!pq.empty())
    {
        int A = pq.top().second.first;
        int B = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        if (Find(A) != Find(B))
        {
            Union(A, B);
            result += cost;
            last = cost;
        }
    }
    

    cout << result - last;

}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

