#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

void BFS(int& answer, int start_index, int* is_visited, vector<vector<int>>& computers)
{
    queue<int> go;
    go.push(start_index);

    while (!go.empty())
    {
        int idx = go.front();
        go.pop();

        // 첫 방문
        if (!is_visited[idx])
        {
            answer++;
        }

        for (int i = 0; i < computers[idx].size(); i++)
        {
            auto computer = computers[idx];
            if (computer[i] && !is_visited[i])
            {
                go.push(i);
                is_visited[i] = 1;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int* is_visited = new int[n];
    

    for (int i = 0; i < n; i++)
    {
        is_visited[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {

        BFS(answer, i, is_visited, computers);
    }



    return answer;
}