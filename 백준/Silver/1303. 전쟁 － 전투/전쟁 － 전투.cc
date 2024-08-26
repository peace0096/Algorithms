#include <iostream>
#include <string>

using namespace std;

int N, M;

int W = 0;
int B = 0;

char arr[100][100];
int visited[100][100];
int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, -1, 0, 1 };
int count1 = 1;

void DFS(int y, int x, char team)
{
    for (int i = 0; i < 4; i++)
    {
        int newY = y + dirY[i];
        int newX = x + dirX[i];

        if (newY < 0 || newY > M - 1 || newX < 0 || newX > N - 1 || visited[newY][newX] || arr[newY][newX] != team)
            continue;

        visited[newY][newX] = visited[y][x] + 1;
        DFS(newY, newX, team);
        count1++;
    }

}

int main() 
{
    cin >> N >> M;
    
    for (int i = 0; i < M; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = line[j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j])
                continue;
            visited[i][j] = 1;
            DFS(i, j, arr[i][j]);

            if (arr[i][j] == 'W')
                W += count1 * count1;
            else
                B += count1 * count1;
            count1 = 1;
        }
    }

    cout << W << '\n' << B;
    

    return 0;
}