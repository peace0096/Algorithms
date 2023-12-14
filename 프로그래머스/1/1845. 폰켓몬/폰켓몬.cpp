#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int count = 0;
    vector<int> founds;
    
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = find(founds.begin(), founds.end(), nums[i]);
        int index = it - founds.begin();
        if (it != founds.end()) continue;
        else
        {
            founds.push_back(nums[i]);
            
            count++;
        }
        if (count == nums.size() / 2) break;

    }

    answer = count;
    return answer;
}
