#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

char arr[500000];
int N;
int R = 0;
int B = 0;

int max_R = 0;
int max_B = 0;
char prev_color = 'R';

int ans = 1;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] == 'R')
        {
            if (prev_color == 'R') R++;
            else
            {
                prev_color = 'R';
                max_B = max(B, max_B);
                B = 0;
                R = 1;
            }
        }
        else
        {
            if(prev_color == 'B') B++;
            else
            {
                prev_color = 'B';
                max_R = max(R, max_R);
                R = 0;
                B = 1;
            }
            
        }

    }
}

void sol()
{
    char post_color = B > R ? 'R' : 'B';

    int i = 0;
    while (i < N)
    {
        int cnt = 0;
        while (i < N && arr[i + cnt] == post_color)
        {
            cnt++;
        }

        if (cnt) ans++;
        i += cnt + 1;
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();
    
    
    return 0;
}

