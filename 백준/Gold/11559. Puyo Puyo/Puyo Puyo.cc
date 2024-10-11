#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

string fields[12] = { "", };

map<char, int> colors;

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, -1, 0, 1};
int visited[12][6] = { 0, };
bool gravity[6] = { false, };

int BombCnt = 0;

// 4개 이상 체크
// 체크되면 -> 터뜨리고, 중력적용. 단, 동시에 여러 뿌요가 터질 수도 있어서 전체 순회 필요.
// 모두 순회했는데 체크 안되면 -> 종료

// 터뜨려주는거

// 중력 적용

void Bomb(int y, int x, char c, vector<pair<int, int>>& BombList)
{
    for (int i = 0; i < 4; i++)
    {
        int newY = y + dirY[i];
        int newX = x + dirX[i];
        if (newX < 0 || newX > 11 || newY < 0 || newY > 11 || visited[newY][newX] != 0) continue;
        if (fields[newY][newX] == c)
        {
            // 만약 같은 색일 경우 -> 연쇄 가능
            visited[newY][newX] = colors[c];
            BombList.push_back({ newY, newX });
            Bomb(newY, newX, c, BombList);
        }
    }
}


void GoBbyooYo()
{
    for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) visited[i][j] = 0;
    for (int i = 0; i < 6; i++) gravity[i] = false;
    
    int IsBombed = false;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            vector<pair<int, int>> BombList;
            char c = fields[i][j];
            if (c == '.') continue;

            visited[i][j] = colors[c];
            BombList.push_back({ i, j });
            Bomb(i, j, c, BombList);

            if (BombList.size() >= 4)
            {
                // 연쇄 가능
                IsBombed = true;
                for (auto pos : BombList)
                {
                    fields[pos.first][pos.second] = '.';
                    gravity[pos.second] = true;
                }
            }

        }
    }

    if (IsBombed)
    {
        // 연쇄 터졌으니까 중력 적용
        BombCnt++;

        for (int i = 0; i < 6; i++)
        {
            if (gravity[i])
            {
                int ColorStartY = -1;
                // 중력 적용해야 함

                int nowY = 0;
                while (nowY < 12)
                {
                    if (fields[nowY][i] == '.')
                    {
                        if (ColorStartY != -1)
                        {
                            for (int j = nowY; j > 0; j--)
                            {
                                
                                fields[j][i] = fields[j-1][i];
                                fields[j - 1][i] = '.';
                            }
                            ColorStartY++;
                        }
                    }

                    else if (fields[nowY][i] != '.' && ColorStartY == -1)
                    {
                        // 첫 블럭일 경우
                        ColorStartY = nowY;
                    }
                    nowY++;
                }

            }
        }

        // 그리고 다시 체크
        GoBbyooYo();
    }

}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    colors['R'] = 1;
    colors['G'] = 2;
    colors['B'] = 3;
    colors['P'] = 4;
    colors['Y'] = 5;
    
    for (int i = 0; i < 12; i++)
    {
        cin >> fields[i];
    }

    GoBbyooYo();


    cout << BombCnt;

    return 0;
}