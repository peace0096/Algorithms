#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    
    int a, b;
    
    
    for(int i = 3; i <= brown - 2; i++)
    {
        int j = brown + 4 - 2 * i;
        if(j % 2 > 0) continue;
        j /= 2;
        // 2 * i + 2 * j = brown + 4
        int yellow_if = (i - 2) * (j - 2);
        if(yellow_if == yellow)
        {
            answer.push_back(max(i, j));
            answer.push_back(min(i, j));
            break;
        }
    }
    
    
    return answer;
}