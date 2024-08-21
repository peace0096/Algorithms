#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
long long arr[100000];

int main() 
{
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int p1 = 0;
    int p2 = 0;
    long long sum = arr[0];
    int count = N + 2;

    while (p1 <= N - 1)
    {
        // 합이 충분하다면
        if (sum >= S)
        {
            count = min(count, p2 - p1 + 1);
            sum -= arr[p1++];
        }
        // 합이 부족하다면
        else if (sum < S)
        {
            if (p2 < N - 1)
            {
                sum += arr[++p2];
            }
                
            else
            {
                if (count == N + 2)
                {
                    break;
                }
                sum -= arr[p1++];
            }
        }
        
    }

    if (count == N + 2)
    {
        cout << 0;
    }
    else
    {
        cout << count;
    }
    

    return 0;
}