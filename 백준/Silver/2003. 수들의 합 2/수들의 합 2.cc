#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int N, M;
int arr[10000];


void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void sol()
{
    int answer = 0;
    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        // 자기자신부터 시작하도록 넣기
        q.push(0);

        int cnt = q.size();
        while (cnt > 0)
        {
            cnt--;
            int num = q.front();
            q.pop();

            int sum = num + arr[i];
            if (sum == M)
            {
                answer++;
            }
            else if (sum < M)
            {
                q.push(sum);
            }

        }

    }


    cout << answer;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

