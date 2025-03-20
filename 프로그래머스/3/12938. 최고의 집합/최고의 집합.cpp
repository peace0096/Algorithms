#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    // 최솟값부터 구하기
    int min_num = s / n;
    int left = s % n;
    
    if(s < n)
    {
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = 0; i < n; i++)
    {
        // s 5
        // n 3
        // left 2
        if(n - left <= i)
        {
            int num = min_num + 1;
            answer.push_back(num);
        }
        else
        {
            answer.push_back(min_num);
        }
        
    }
    
    return answer;
}