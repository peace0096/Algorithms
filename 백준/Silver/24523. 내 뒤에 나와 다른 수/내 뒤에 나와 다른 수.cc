#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
long long A[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    
    int previous_stack = 1;
    int previous = A[1];
    for (int i = 2; i <= N; i++)
    {
        if (previous != A[i])
        {
            for (int j = 0; j < previous_stack; j++) cout << i << ' ';
            previous = A[i];
            previous_stack = 1;
        }
        else
        {
            previous_stack++;
        }


    }

    while (previous_stack--)
    {
        cout << -1 << ' ';
    }


    return 0;
}

