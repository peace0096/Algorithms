#include <iostream>
#include <queue>
using namespace std;

long long A, B;
bool flag = false;
int cnt = 0;

void BFS()
{
    queue<long long> q;
    q.push(A);
    while (!q.empty())
    {
        cnt++;
        int size = q.size();
        // 계층 하나
        while (size > 0)
        {
            size--;
            long long n = q.front();
            q.pop();
            if (n == B)
            {
                flag = true;
                return;
            }
            if (n * 10 < B)
            {
                q.push(n * 10 + 1);
            }
            if (n * 2 - 1 < B)
            {
                q.push(n * 2);
            }
            
        }
    }
}

int main() 
{
    cin >> A >> B;

    BFS();
    if (flag)
        cout << cnt;
    else
        cout << -1;

    

    return 0;
}