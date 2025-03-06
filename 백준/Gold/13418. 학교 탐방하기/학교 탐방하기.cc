#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;

// 점선 : 오르막길
// 실선 : 내리막길
// 입구 : 0
// 내리막 -> 다시 올라가는 경우 고려 X
// 오르막길 k번 오를 경우 k^2 -> 피로도

int N, M;
vector<int> upper_graph[1001];
vector<int> under_graph[1001];
int parent[1001];
vector<int> v1;
vector<int> v2;

void input()
{
    cin >> N >>  M;
    for (int i = 0; i <= M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        
        if (C == 0)
        {
            upper_graph[A].push_back(B);
            v1.push_back(A);
        }
        else
        {
            under_graph[A].push_back(B);
            v2.push_back(A);
            //q1.push(B);
        }

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
    parent[parent_x] = parent_y;
}

void sol()
{
    // 최선의 경로
    int result = 0;

    // 최악의 경로
    int result1 = 0;
    for (int i = 0; i <= N; i++) parent[i] = i;
    for (auto now : v2)
    {

        for (auto next : under_graph[now])
        {
            if (Find(next) != Find(now))
            {
                Union(now, next);
            }
        }
    }

    

    for (auto now : v1)
    {
        for (auto next : upper_graph[now])
        {
            if (Find(next) != Find(now))
            {
                Union(now, next);
                result++;
            }
        }
    }

    // 최악의 케이스 계산
    for (int i = 0; i <= N; i++) parent[i] = i;
    for (auto now : v1)
    {
        for (auto next : upper_graph[now])
        {
            if (Find(next) != Find(now))
            {
                Union(now, next);
                result1++;
            }
        }
    }

    for (auto now : v2)
    {

        for (auto next : under_graph[now])
        {
            if (Find(next) != Find(now))
            {
                Union(now, next);
            }
        }
    }

    cout << result1 * result1 - result * result;

    
    


    

}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

