#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    // 초기화
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();

    int direct_x[] = { -1, 0, 1, 0 };
    int direct_y[] = { 0, 1, 0, -1 };

    // 방문 여부
    vector<vector<bool>> is_visited(n, vector<bool>(m, false));
    // 해당 위치까지 오기까지의 최단 거리
    vector<vector<int>> dist(n, vector<int>(m, 10001));

    // Queue
    queue<pair<int, int>> go;

    // 시작
    go.push(make_pair(0, 0));
    dist[0][0] = 1;
    is_visited[0][0] = true;

    while (!go.empty())
    {
        auto pos = go.front();
        go.pop();

        int y = pos.first;
        int x = pos.second;

        if (y == n - 1 && x == m - 1)
        {
            answer = dist[y][x];
            break;
        }

        for (int i = 0; i < 4; i++ )
        {
            int new_y = y + direct_y[i];
            int new_x = x + direct_x[i];

            if (new_y < 0 || new_y >= n ||
                new_x < 0 || new_x >= m ||
                is_visited[new_y][new_x] ||
                maps[new_y][new_x] == 0)
                continue;

            is_visited[new_y][new_x] = true;
            go.push(make_pair(new_y, new_x));
            dist[new_y][new_x] = min(dist[new_y][new_x], dist[y][x] + 1);
        }
    }

    return answer;
}