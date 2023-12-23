#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int DFS(vector<int>& numbers, int sum, int index, int& target)
{
    int n = numbers[index];


    int sum1 = sum + n * (-1);
    int sum2 = sum + n;


    if (index == numbers.size() - 1)
    {
        int count = 0;
        if (target == sum1) count++;
        if (target == sum2) count++;
        return count;
    }

    int count = 0;
    count += DFS(numbers, sum1, index + 1, target);
    count += DFS(numbers, sum2, index + 1, target);

    return count;
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = DFS(numbers, 0, 0, target);

    return answer;
}