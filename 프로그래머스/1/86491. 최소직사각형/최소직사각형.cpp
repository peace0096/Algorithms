#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width = 0;
    int height = 0;

    for (auto v : sizes)
    {
        int mwidth = max(v[0], v[1]);
        int mheight = min(v[0], v[1]);

        width = max(width, mwidth);
        height = max(height, mheight);
    }
    answer = width * height;


    return answer;
}