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

// first : planet, second : cost
int parent[1001];
long long cost[1001][1001];

struct cmp
{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2)
    {
        return cost[p1.first][p1.second] > cost[p2.first][p2.second];
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;


// 부모 찾기
int Find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    int parent_x = Find(x);
    int parent_y = Find(y);
    parent[parent_x] = parent_y;
}


void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> cost[i][j];
            pq.push({ i, j });
        }
    }
}



void sol()
{
    long long result = 0;

    for (int i = 1; i <= N; i++) parent[i] = i;

    while (!pq.empty())
    {
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();

        if (Find(a) != Find(b))
        {
            Union(a, b);
            result += cost[a][b];
        }

    }
    
    cout << result;

}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

