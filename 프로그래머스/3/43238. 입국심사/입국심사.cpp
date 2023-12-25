#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

long long solution(int n, vector<int> times) {

    sort(times.begin(), times.end());
    
    long max_time = (long)times[times.size() - 1] * n;
    long min_time = 1;
    long answer = max_time;

    while (min_time <= max_time)
    {
        long temp_n = 0;
        long avg_time = (max_time + min_time) / 2;

        for (auto t : times)
        {
            temp_n += avg_time / t;
            if (temp_n >= n) break;
        }

        if (temp_n < n)
        {
            min_time = avg_time + 1;
            
        }
        else
        {
            answer = min(answer, avg_time);
            max_time = avg_time - 1;
        }
    }

    return answer;
}


// 7 10 14 20 21 28 30 ... 42 50 60