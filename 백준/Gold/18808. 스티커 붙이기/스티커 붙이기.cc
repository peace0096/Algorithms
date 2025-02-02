#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M, K;
bool notebook[40][40] = { false, };

void Sol()
{
    cin >> N >> M >> K;

    for (int k = 0; k < K; k++)
    {
        int R, C;
        cin >> R >> C;

        int sticker[10][10];

        for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
        {
            cin >> sticker[i][j];
        }

        // 0도, 90도, 270도 돌리기

        for (int r = 0; r < 4; r++)
        {
            bool IsDone = false;
            vector<vector<int>> rotated_sticker;

            if (r == 0)
            {
                for (int i = 0; i < R; i++)
                {
                    rotated_sticker.push_back(vector<int>());
                    for (int j = 0; j < C; j++)
                    {
                        rotated_sticker[i].push_back(sticker[i][j]);
                    }
                }
            }
            else if (r == 1)
            {
                for (int i = 0; i < C; i++)
                {
                    rotated_sticker.push_back(vector<int>());
                    for (int j = 0; j < R; j++)
                    {
                        rotated_sticker[i].push_back(sticker[R - 1 - j][i]);
                    }

                }
            }
            else if (r == 2)
            {
                for (int i = 0; i < R; i++)
                {
                    rotated_sticker.push_back(vector<int>());
                    for (int j = 0; j < C; j++)
                    {
                        rotated_sticker[i].push_back(sticker[R - 1 - i][C - 1 - j]);
                    }
                }
            }
            else if (r == 3)
            {
                for (int i = 0; i < C; i++)
                {
                    rotated_sticker.push_back(vector<int>());
                    for (int j = 0; j < R; j++)
                    {
                        rotated_sticker[i].push_back(sticker[j][C - 1 - i]);
                    }

                }
            }

            
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    bool CanPut = true;

                    int rotated_R = rotated_sticker.size();
                    int rotated_C = rotated_sticker[0].size();

                    // 스티커 넣을 수 있는 지 확인 시작
                    for (int y = 0; y < rotated_R; y++) for (int x = 0; x < rotated_C; x++)
                    {
                        // 영역 넘어가면 스티커 못 붙힘
                        if (y + i >= N || x + j >= M)
                        {
                            CanPut = false;
                            break;
                        }

                        // 이미 붙혀져있으면 못 붙힘
                        if (rotated_sticker[y][x] == 1 && notebook[i + y][j + x])
                        {
                            CanPut = false;
                            break;
                        }
                    }

                    if (CanPut)
                    {
                        for (int y = 0; y < rotated_R; y++) for (int x = 0; x < rotated_C; x++)
                        {
                            if (rotated_sticker[y][x] == 1)
                            {
                                notebook[i + y][j + x] = true;
                            }
                        }
                        IsDone = true;
                        break;
                    }
                    
                }
                if (IsDone) break;
            }
            if (IsDone) break;
        }

        
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
    {
        if (notebook[i][j]) cnt++;
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Sol();
    

    
    return 0;
}

