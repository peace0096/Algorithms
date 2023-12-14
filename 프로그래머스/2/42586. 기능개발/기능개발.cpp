#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while (!progresses.empty())
    {
        int count = 0;
        for (int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }

        for(auto progress : progresses)
        {
            if (progress >= 100) count++;
            else break;
        }

        if (count > 0) answer.push_back(count);

        for (int i = 0; i < count; i++)
        {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
        }
    }
    return answer;
}