#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int N, M;
int arr[1000];
pair<pair<int, int>, int> students[20];


bool compare(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2)
{
    if(p1.first.first == p2.first.first)
    {
        // 추천 수 같으면
        return p1.first.second < p2.first.second;
    }
    return p1.first.first < p2.first.first;
    
};

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> arr[i];
}

void sol()
{

    // first : 추천 수, second : 넣은 시점
    
    for (int i = 0; i < M; i++)
    {
        sort(students, students + N, compare);
        bool flag = false;
        for (int j = 0; j < N; j++)
        {
            if (students[j].second == arr[i])
            {
                // 이미 추천받은 학생이라면 추천 증가, 추천 시점 갱신
                students[j].first.first = students[j].first.first + 1;
                // students[j].first.second = i;
                flag = true;
                break;
            }
            
        }

        if (!flag)
        {


            // 새로운 학생 추가
            students[0] = { {1, i}, arr[i]};
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        if (students[i].second != 0) pq.push(students[i].second);
    }

    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    
    return 0;
}

