#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int area[100][100];

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, -1, 0, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
    {
        cin >> area[i][j];
    }

    int n = 0;
    int max_area_num = 0;

    while (n <= 100)
    {
        int area_num = 0;
        bool visited[100][100] = { false, };

        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
        {
            
            if (!visited[i][j] && area[i][j] > n)
            {
                // 잠기지 않은 영역 발견
                area_num++;
                visited[i][j] = true;

                // 이곳 주위의 영역 탐색 시작
                queue<pair<int, int>> q;
                q.push({ i, j });

                while (!q.empty())
                {
                    int now_y = q.front().first;
                    int now_x = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int next_y = now_y + dirY[k];
                        int next_x = now_x + dirX[k];

                        if (next_y < 0 || next_y >= N ||
                            next_x < 0 || next_x >= N || visited[next_y][next_x] || area[next_y][next_x] <= n) continue;

                        visited[next_y][next_x] = true;
                        q.push({ next_y, next_x });
                    }
                }
                
            }
        }
        n++;
        max_area_num = max(max_area_num, area_num);
    }
    
    cout << max_area_num;


    return 0;
}

