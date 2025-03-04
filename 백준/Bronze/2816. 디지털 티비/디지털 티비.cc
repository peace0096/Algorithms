#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int N;
string channels[100];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> channels[i];
}

void sol()
{
    int cursor = 0;
    while (true)
    {
        if (channels[0] != "KBS1")
        {
            if (channels[cursor] != "KBS1")
            {
                // 내려가면서 찾기
                cursor++;
                cout << 1;
            }
            else
            {
                // 만약 찾았다면
                while (channels[0] != "KBS1")
                {
                    channels[cursor] = channels[cursor - 1];
                    channels[cursor - 1] = "KBS1";
                    cursor--;
                    cout << 4;
                }
            }
        }
        else if (channels[1] != "KBS2")
        {
            if (channels[cursor] != "KBS2")
            {
                // 내려가면서 찾기
                cursor++;
                cout << 1;
            }
            else
            {
                // 만약 찾았다면
                while (channels[1] != "KBS2")
                {
                    channels[cursor] = channels[cursor - 1];
                    channels[cursor - 1] = "KBS2";
                    cursor--;
                    cout << 4;
                }
            }
        }

        if (channels[0] == "KBS1" && channels[1] == "KBS2")
            return;
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

