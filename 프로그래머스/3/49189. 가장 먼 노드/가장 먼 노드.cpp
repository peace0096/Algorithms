#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> graph(n + 1, vector<int>());
    vector<bool> is_visited(n + 1, false);

    for (int i = 0; i < edge.size(); i++)
    {
        int first = edge[i][0];
        int second = edge[i][1];

        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    // 검증용
    //for (int i = 1; i < graph.size(); i++)
    //{
    //    cout << i << " : ";
    //    for (int j = 0; j < graph[i].size(); j++)
    //    {
    //        cout << graph[i][j] << " ";
    //    }
    //    cout << '\n';
    //}

    queue<int> go;
    vector<int> dists(n + 1, 0);

    go.push(1);
    dists[1] = 0;
    is_visited[1] = true;
    
    while (!go.empty())
    {
        int node = go.front();
        go.pop();

        for (int next : graph[node])
        {
            if (!is_visited[next])
            {
                go.push(next);
                dists[next] =  dists[node] + 1;
                is_visited[next] = true;
            }
        }

    }

    

    int max_dis = 0;
    //cout << "===dists===" << '\n';
    for (int dist : dists)
    {
        //cout << dist << '\n';
        if (max_dis < dist)
        {
            
            max_dis = dist;
            answer = 1;
        }
        else if (max_dis == dist)
        {
            answer++;
        }
    }

    return answer;
}