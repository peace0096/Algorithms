#include <iostream>
using namespace std;

string line1;
string line2;
int dp[1001][1001] = { 0, };
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> line1 >> line2;
    line1.insert(line1.begin(), ' ');
    line2.insert(line2.begin(), ' ');
    dp[0][0] = 0;

    for (int i = 1; i < line1.size(); i++)
    {
        for (int j = 1; j < line2.size(); j++)
        {
            if (line1[i] == line2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    }
    
    cout << dp[line1.size() - 1][line2.size() - 1];
    
    return 0;
}

