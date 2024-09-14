#include <iostream>

using namespace std;

int N, K;
int DP[101][100001];
int W[101];
int V[101];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i] >> V[i];
    }


    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j < W[i])
            {
                DP[i][j] = DP[i - 1][j];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], V[i] + DP[i - 1][j - W[i]]);
            }
        }
    }

    cout << DP[N][K];

	
    return 0;
}