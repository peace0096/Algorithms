#include <string>
#include <vector>

using namespace std;

long long dp[101][101];
long long dirY[2] = {1, 0};
long long dirX[2] = {0, 1};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(auto puddle : puddles)
    {
        dp[puddle[0]][puddle[1]] = -1;
    }
    
    dp[1][1] = 1;
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dp[i][j] == -1) continue;
            
            for(int k = 0; k < 2; k++)
            {
                int next_y = i + dirY[k];
                int next_x = j + dirX[k];
                
                if(next_y > m || next_x > n || dp[next_y][next_x] == -1) continue;
                
                dp[next_y][next_x] += dp[i][j] % 1000000007;
                
            }
            
        }
        
    }
    
    answer = dp[m][n] % 1000000007;
    
    return answer;
}