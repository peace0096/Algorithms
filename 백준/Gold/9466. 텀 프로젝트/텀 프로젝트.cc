#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
int visited[100001];

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            arr[j] = x; visited[j] = 0;
        }

        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == 0)
            {

                //j 탐색시작
                queue<int> q;
                int go = j;
                //visited[go] = go;
                q.push(go);
                
                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();

                    // 처음 왔을 경우
                    if (visited[x] == 0)
                    {
                        q.push(arr[x]);
                        visited[x] = go;
                    }
                    else
                    {
                        // 이미 지나온 곳을 만났다면
                        while (visited[x] != -1 && visited[x] == go)
                        {
                            // 한번 더 돌아서 그룹표시
                            visited[x] = -1;
                            x = arr[x];
                        }

                        
                    }
                }

            }
        }
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] != -1) count++;
        }

        cout << count << '\n';



    }
}
