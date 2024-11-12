#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long N, L;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    // 
    // N = (x + 1) + ... + (x + L)
    // N = Lx + 1 + ... + L
    // N = Lx + L(L+1)/2
    // Lx = N - L(L+1)/2
    // L = 수열의 개수(최소 L개)
    // x = 첫항 - 1

    for (int i = L; i <= 100; i++)
    {
        int Temp = N - i * (i + 1) / 2;
        if (Temp % i == 0)
        {
            // x을 구하기 위해 i를 나눈다
            // 근데 홀수면 안됨
            int x = Temp / i;

            if (x + 1 >= 0)
            {
                // 음수면 안됨
                for (int k = 1; k <= i; k++)
                {
                    cout << (x + k) << ' ';
                }
                return 0;
            }
            
        }
    }

    cout << -1;

    return 0;
}

