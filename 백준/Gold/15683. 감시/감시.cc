#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M;
int space[8][8];
vector<pair<int, int>> cctv;
int space_temp[8][8];
int cctv_rotate_angle[8];
int wall_cnt = 0;

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
    {
        cin >> space[i][j];
        if (space[i][j] == 6) wall_cnt++;
        else if (space[i][j] != 0) cctv.push_back({ i, j });
    }
}

void Search(int angle, int y, int x)
{
    if (angle == 0)
    {
        // 위쪽
        for (int i = y - 1; i >= 0; i--)
        {
            if (space_temp[i][x] == 0) space_temp[i][x] = -1;
            else if (space_temp[i][x] == 6) break;
        }
    }
    else if (angle == 1)
    {
        // 오른쪽
        for (int i = x + 1; i < M; i++)
        {
            if (space_temp[y][i] == 0) space_temp[y][i] = -1;
            else if (space_temp[y][i] == 6) break;
        }
    }
    else if (angle == 2)
    {
        // 아래쪽
        for (int i = y + 1; i < N; i++)
        {
            if (space_temp[i][x] == 0) space_temp[i][x] = -1;
            else if (space_temp[i][x] == 6) break;
        }
    }
    else if (angle == 3)
    {
        // 왼쪽
        for (int i = x - 1; i >= 0; i--)
        {
            if (space_temp[y][i] == 0) space_temp[y][i] = -1;
            else if (space_temp[y][i] == 6) break;
        }
    }
}

int Cnt()
{
    int cnt = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
    {
        if (space_temp[i][j] == -1) cnt++;
    }

    return cnt;
}

int BackTracking(int n)
{
    if (n == cctv.size())
    {
        // 복사본
        
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        {
            space_temp[i][j] = space[i][j];
        }

        for (int i = 0; i < cctv.size(); i++)
        {
            int y = cctv[i].first;
            int x = cctv[i].second;
            int cctv_angle = cctv_rotate_angle[i];
            int cctv_category = space[y][x];

            if (cctv_category == 1)
            {
                Search(cctv_angle, y, x);
            }
            else if (cctv_category == 2)
            {
                Search(cctv_angle, y, x);
                Search((cctv_angle + 2) % 4, y, x);
            }
            else if (cctv_category == 3)
            {
                Search(cctv_angle, y, x);
                if (cctv_angle == 0) Search(3, y, x);
                else Search((cctv_angle - 1) % 4, y, x);
            }
            else if (cctv_category == 4)
            {
                Search(cctv_angle, y, x);
                if (cctv_angle == 0) Search(3, y, x);
                else Search((cctv_angle - 1) % 4, y, x);
                Search((cctv_angle + 2) % 4, y, x);
            }
            else if (cctv_category == 5)
            {
                Search(cctv_angle, y, x);
                if (cctv_angle == 0) Search(3, y, x);
                else Search((cctv_angle - 1) % 4, y, x);
                Search((cctv_angle + 2) % 4, y, x);
                Search((cctv_angle + 1) % 4, y, x);
            }
        }

        // 개수 세기
        int cnt = Cnt();
        return cnt;
    }

    cctv_rotate_angle[n] = 0;
    int result = BackTracking(n + 1);

    cctv_rotate_angle[n] = 1;
    result = max(result, BackTracking(n + 1));

    cctv_rotate_angle[n] = 2;
    result = max(result, BackTracking(n + 1));

    cctv_rotate_angle[n] = 3;
    result = max(result, BackTracking(n + 1));

    // 0, 1, 2, 3
    // 0, 90, 180, 270

    return result;
}

void Sol()
{
    int result = BackTracking(0);
    cout << (N * M - result - cctv.size() - wall_cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Sol();
    
    return 0;
}

