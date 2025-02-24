#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, M;
int A[1000000];
int B[1000000];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
}

void sol()
{
    sort(A, A + N);
    sort(B, B + M);

    int a = 0;
    int b = 0;
    while (a < N && b < M)
    {
        (A[a] < B[b]) ? cout << A[a++] : cout << B[b++];
        cout << ' ';

        if (a == N)
        {
            for (; b < M; b++) cout << B[b] << ' ';
            break;
        }
        if (b == M)
        {
            for (; a < N; a++) cout << A[a] << ' ';
            break;
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    sol();
    
    return 0;
}

