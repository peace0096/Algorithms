#include <iostream>
#include <queue>
using namespace std;

int N, M;
char board[20][20];
queue<pair<pair<int, int>, pair<int, int>>> q;

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};
int cnt = 0;

bool isDropped(pair<int, int> coin)
{
    return coin.first < 0 || coin.first > N - 1
        || coin.second < 0 || coin.second > M - 1;
}

bool isWall(pair<int, int> coin)
{
    return board[coin.first][coin.second] == '#';
}

bool isSame(pair<int, int> coin1, pair<int, int> coin2)
{
    return (coin1.first == coin2.first && coin1.second == coin2.second);
}

void BFS()
{
    while (!q.empty() && cnt <= 10)
    {
        cnt++;
        int size = q.size();

        while (size-- > 0)
        {
            pair<pair<int, int>, pair<int, int>> two_coins = q.front();
            q.pop();
            pair<int, int> coin1 = two_coins.first;
            pair<int, int> coin2 = two_coins.second;

            for (int i = 0; i < 4; i++)
            {
                pair<int, int> coin1_next = { coin1.first + dirY[i], coin1.second + dirX[i] };
                pair<int, int> coin2_next = { coin2.first + dirY[i], coin2.second + dirX[i] };

                bool isCoin1_Dropped = isDropped(coin1_next);
                bool isCoin2_Dropped = isDropped(coin2_next);

                // 1. 둘 다 안 떨어졌다면, 다음 큐에 넣기
                if (isCoin1_Dropped == false && isCoin2_Dropped == false)
                {
                    bool isCoin1_Walled = isWall(coin1_next);
                    bool isCoin2_Walled = isWall(coin2_next);

                    if (isCoin1_Walled == true && isCoin2_Walled == true)
                    {
                        q.push({ coin1, coin2 });
                    }
                    else if (isCoin1_Walled == true && isCoin2_Walled == false)
                    {
                        q.push({ coin1, coin2_next });
                    }
                    else if (isCoin1_Walled == false && isCoin2_Walled == true)
                    {
                        q.push({ coin1_next, coin2 });
                    }
                    else if(isCoin1_Walled == false && isCoin2_Walled == false)
                    {
                        q.push({ coin1_next, coin2_next });
                    }
                }
                // 2. 둘 중 하나만 떨어졌다면 끝!
                else if (isCoin1_Dropped != isCoin2_Dropped)
                {
                    return;
                }
            }
        }
    }


}

int main() 
{
    cin >> N >> M;
    pair<int, int> coin1 = { -1, -1 };
    pair<int, int> coin2 = { -1, -1 };
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
    {
        cin >> board[i][j];
        if (board[i][j] == 'o')
        {
            if (coin1.first == -1)
            {
                coin1 = { i, j };
            }
            else
            {
                coin2 = { i, j };
            }
        }
    }
    
    q.push({ coin1, coin2 });
    BFS();

    if (cnt == 11)
    {
        cout << -1;
    }
    else
    {
        cout << cnt;
    }

    return 0;
}