#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;


long long X, Y, W, S;

void input()
{
    cin >> X >> Y >> W >> S;
}


// 1 대각선 => 1가로 + 1세로

// 2, 0 = 세로2 or 대각선2
// 0, 2 = 가로2 or 대각선2
// 1, 1 = 가로1세로1 or 대각선1
// -1, 1 = 가로1세로1 or 대각선1
// 1, -1 = 가로1세로1 or 대각선1


void sol()
{
    long long ans = 0;
    
    ans = (X + Y) * W;  // 가로세로만 쓰기

    long long mod = (X + Y) % 2;

    ans = min(ans, (max(X, Y) - mod) * S + mod * W);  // 최대한 대각선만
    ans = min(ans, min(X, Y) * S + abs(X - Y) * W);   // 섞어서 쓰기
    
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

