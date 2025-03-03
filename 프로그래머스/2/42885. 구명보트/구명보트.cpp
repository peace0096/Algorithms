#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int cnt[241];

int solution(vector<int> people, int limit) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    sort(people.begin(), people.end());
    for(int i = 0; i < people.size(); i++) 
    {
        cnt[people[i]]++;
        pq.push(people[i]);
    }
    
    
    for(int i = people.size() - 1; i >= 0; i--)
    {
        if(cnt[people[i]] == 0) continue;
        cnt[people[i]]--;
        
        int remain = limit - people[i];
        
        while(remain >= pq.top())
        {
            // 개수 체크
            if(cnt[pq.top()] > 0)
            {
                cnt[pq.top()]--;
                break;
            }
            pq.pop();
        }
        answer++;
        
    }
    
    
    return answer;
}