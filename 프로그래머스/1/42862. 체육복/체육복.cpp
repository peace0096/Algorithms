#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = 1;
    for (int i = 0; i < lost.size(); i++)
        arr[lost[i] - 1]--;
    for (int i = 0; i < reserve.size(); i++)
        arr[reserve[i] - 1]++;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (i > 0 && arr[i - 1] == 2)
            {
                arr[i - 1] = 1;
                arr[i] = 1;
            }
            else if (i + 1< n && arr[i + 1] == 2)
            {
                arr[i] = 1;
                arr[i + 1] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (arr[i] > 0) answer++;

    delete[] arr;

    return answer;
}