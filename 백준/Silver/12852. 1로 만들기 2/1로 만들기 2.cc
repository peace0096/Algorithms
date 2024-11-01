#include <iostream>
using namespace std;

// first = 연산횟수, second = 최소의 연산 가능한 다음 숫자
pair<int, int> dp[1000001] = { };
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;


    dp[1] = { 0, 0 };
    dp[2] = { 1, 1 };
    dp[3] = { 1, 1 };

    for (int i = 4; i <= N; i++)
    {
        dp[i] = { dp[i - 1].first + 1, i - 1};
        if (i % 3 == 0)
        {
            pair<int, int> result = { dp[i / 3].first + 1, i /3 };
            if (result.first < dp[i].first)
                dp[i] = result;
        }
        if (i % 2 == 0)
        {
            pair<int, int> result = { dp[i / 2].first + 1, i / 2 };
            if (result.first < dp[i].first)
                dp[i] = result;
        }



    }

    cout << dp[N].first << '\n';

    int n = N;
    while (n != 0)
    {
        cout << n << ' ';
        n = dp[n].second;
    }
    
    return 0;
}

