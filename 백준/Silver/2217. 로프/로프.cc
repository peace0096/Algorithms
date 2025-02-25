#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int arr[100000];
int max_weight = 0;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
}

void sol()
{
    sort(arr, arr + N, greater<int>());

    // 풀이시작
    // 제일 큰거부터 가져오기

    for (int i = 0; i < N; i++)
    {
        max_weight = max(max_weight, (i + 1) * arr[i]);
    }
    cout << max_weight;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();
    
    
    return 0;
}

