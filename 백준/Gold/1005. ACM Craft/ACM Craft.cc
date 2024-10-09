#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;

void Test()
{
    int N, K;
    int building_time[1001];
    vector<int> next_build_rules[1001];
    int dest;
    int indegree[1001] = { 0, };

    // 이미 완성된 빌딩 시간
    int time[1001];

    // 만드는 중인 빌딩 시간
    vector<int> times[1001];

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        cin >> building_time[i];
        time[i] = building_time[i];
    }

    for (int i = 1; i <= K; i++)
    {
        int A, B;
        cin >> A >> B;
        next_build_rules[A].push_back(B);
        indegree[B]++;
    }
    cin >> dest;

    queue<int> q;
    
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        

        for (int i = 0; i < next_build_rules[n].size(); i++)
        {
            int next = next_build_rules[n][i];

            indegree[next]--;
            times[next].push_back(time[n]);

            if (indegree[next] == 0)
            {
                q.push(next);
                int max_time = 0;
                for (int j = 0; j < times[next].size(); j++)
                {
                    max_time = max(max_time, times[next][j]);
                }
                time[next] += max_time;

            }
        }
    }


    cout << time[dest] << '\n';

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