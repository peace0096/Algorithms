#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<long long> pq;
    
    for(auto e : works) pq.push(e);
    
    while(n > 0)
    {
        long long now = pq.top();
        if(now == 0) break;
        
        pq.pop();
        n--;
        pq.push(now - 1  > 0 ? now - 1 : 0);
        
    }
    
    while(!pq.empty())
    {
        long long now = pq.top(); pq.pop();
        answer += now * now;
    }
    
    return answer;
}