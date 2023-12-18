#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto s : scoville)
        pq.push(s);

    if (pq.top() >= K)
        return answer;

    int k = pq.size() - 1;

    while (k--)
    {
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        pq.push(min1 + min2 * 2);
        answer++;

        if (pq.top() >= K) return answer;
    }

    return -1;
}