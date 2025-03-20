#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int B_idx = B.size() - 1;
    
    // A의 약한 놈부터
    for(int i = A.size() - 1; i >= 0; i--)
    {
        if(A[i] < B[B_idx])
        {
            answer++;
            B_idx--;
        }
    }
    
    
    return answer;
}