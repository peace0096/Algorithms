#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int N, M, T;
int space[100][100];

int visited[100][100];

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

bool find_sword = false;
int sword_y, sword_x;

void input()
{
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
    {
        cin >> space[i][j];
    }
}

void sol()
{
    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_y = y + dirY[i];
            int next_x = x + dirX[i];
            

            // 벽, 아웃 레인지, 방문여부 체크
            if (next_y < 0 || next_y >= N ||
                next_x < 0 || next_x >= M ||
                space[next_y][next_x] == 1 ||
                visited[next_y][next_x] != 0) continue;

            q.push({ next_y, next_x });
            visited[next_y][next_x] = visited[y][x] + 1;

            if (space[next_y][next_x] == 2)
            {
                find_sword = true;
                sword_y = next_y;
                sword_x = next_x;

            }

            if (next_y == N - 1 && next_x == M - 1)
            {
                // 공주 찾음
                int cost = visited[next_y][next_x];

                if (find_sword)
                {
                    // 검 들고 간거랑 비교
                    int cost_sword = visited[sword_y][sword_x] + (N - 1 - sword_y) + (M - 1 - sword_x);
                    cost = min(cost, cost_sword);
                }

                if (cost <= T) cout << cost;
                else cout << "Fail";
                return;
            }

        }
    }

    // 실패 판정 전에, 검 먹은 위치로부터 코스트 마지막으로 계산
    if (find_sword)
    {
        int cost_sword = visited[sword_y][sword_x] + (N - 1 - sword_y) + (M - 1 - sword_x);
        if (cost_sword <= T)
        {
            cout << cost_sword;
            return;
        }
    }
    
    cout << "Fail";
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

