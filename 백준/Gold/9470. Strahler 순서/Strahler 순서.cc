#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> edges;
int indegree[1001];
int T;

int K, M, P;

void Test()
{
    edges = vector<vector<int>>(1001);
    
    int strahler[1001] = { 0, };

    // 부모 노드의 순서 보관
    vector<int> parent_strahlers[1001];

    queue<int> q;

    cin >> K >> M >> P;

    // K : 테스트번호
    // M : 노드 개수
    // P : 간선 개수

    for (int i = 0; i < P; i++)
    {
        int A, B;
        cin >> A >> B;
        edges[A].push_back(B);
        indegree[B]++;
    }

    for (int i = 1; i <= M; i++)
    {
        if (indegree[i] == 0)
        {
            // 전입차수가 1인 것들 = 순서 1
            q.push(i);
            strahler[i] = 1;
        }
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int i = 0; i < edges[now].size(); i++)
        {
            int next = edges[now][i];
            indegree[next]--;
            parent_strahlers[next].push_back(strahler[now]);

            if (indegree[next] == 0)
            {
                // 전입차수가 0이 된다면 -> 모든 부모의 강이 이곳에 도착했다.
                q.push(next);
                int max_strahler = 0;

                for (int j = 0; j < parent_strahlers[next].size(); j++)
                {
                    max_strahler = max(max_strahler, parent_strahlers[next][j]);
                }

                // 가장 순서가 높은 strahler의 개수를 구하라
                int cnt = 0;
                for (int j = 0; j < parent_strahlers[next].size(); j++)
                {
                    if (max_strahler == parent_strahlers[next][j]) cnt++;
                }

                if (cnt > 1) strahler[next] = max_strahler + 1;
                else if (cnt == 1) strahler[next] = strahler[now];
            }
        }

    }

    cout << K << " ";

    int result = 0;
    for (int i = 1; i <= M; i++)
    {
        result = max(result, strahler[i]);
    }

    cout << result << '\n';

   

}

int main() 
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        Test();
    }

    return 0;
}