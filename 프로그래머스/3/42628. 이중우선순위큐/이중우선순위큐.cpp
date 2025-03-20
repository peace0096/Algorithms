#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    
    for(auto operation : operations)
    {
        int num = stoi(operation.substr(2, operation.size() - 2));
        
        if(operation[0] == 'I')
        {
            !pq1.empty() ? pq1.push(num) : pq2.push(num);            
        }
        else
        {
            if(num == 1)
            {
                if(!pq1.empty())
                {
                    pq1.pop();
                }
                else if(!pq2.empty())
                {
                    pq2.pop();
                }
            }
            else
            {
                if(!pq1.empty())
                {
                    while(pq1.size() > 1)
                    {
                        pq2.push(pq1.top());
                        pq1.pop();
                    }
                    pq1.pop();
                }
                else if(!pq2.empty())
                {
                    while(pq2.size() > 1)
                    {
                        pq1.push(pq2.top());
                        pq2.pop();
                    }
                    pq2.pop();
                }
            }
        }
        
        
    }
    // 모두 비어있으면
    if(pq1.empty() && pq2.empty())
    {
        answer.push_back(0); answer.push_back(0);
        
        return answer;
    }
    
    // 최댓값
    answer.push_back(!pq1.empty() ? pq1.top() : pq2.top());
    !pq1.empty() ? pq1.pop() : pq2.pop();
    
    
    // 최솟값
    while(pq1.size() > 1 || pq2.size() > 1)
    {
        !pq1.empty() ? pq1.pop() : pq2.pop();
    }
    if(!pq1.empty())
    {
        answer.push_back(pq1.top());
    }
    else if(!pq2.empty())
    {
        answer.push_back(pq2.top());
    }
    
    if(answer.size() == 1)
    {
        answer.push_back(answer[0]);
    }
    
    return answer;
}