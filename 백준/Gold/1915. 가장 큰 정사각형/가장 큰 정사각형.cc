#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;

int N, M;
char space[1000][1000];
int sum[1000][1000];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> space[i][j];
}


void sol()
{
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
    {
        sum[i][j] = space[i][j] == '1' ? 1 : 0;
        if (i > 0) sum[i][j] += sum[i - 1][j];
        if (j > 0) sum[i][j] += sum[i][j - 1];
        if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];

    }

    int result = 0;

    // one : 한 변의 길이
    for (int one = 1; one <= N; one++)
    {
        bool flag = false;
        for (int i = one - 1; i < N; i++)
        {
            for(int j = one - 1; j < M; j++)
            {
                int now = sum[i][j];

                if (i - one >= 0) now -= sum[i - one][j];
                if (j - one >= 0) now -= sum[i][j - one];
                if (i - one >= 0 && j - one >= 0) now += sum[i - one][j - one];

                if (one * one == now)
                {
                    bool is_nemo = true;
                    for (int k = i; k > i - one; k--) 
                    {
                        for (int l = j; l > j - one; l--)
                        {
                            if (space[k][l] == '0')
                            {
                                is_nemo = false;
                                break;
                            }
                        }
                    }
                    if (!is_nemo) continue;

                    result = max(result, now);
                    flag = true;
                    break;
                }
                
            }
            if (flag) break;
        }
    }

    cout << result;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

