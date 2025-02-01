#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> wheels[5];
int K;

void Change(int wheel_num, int direct)
{
    // 현재 톱니 돌리기
    if (direct == 1)
    {
        // 시계 방향
        int num_11 = *(wheels[wheel_num].end() - 1);
        wheels[wheel_num].erase(wheels[wheel_num].end() - 1);
        wheels[wheel_num].insert(wheels[wheel_num].begin(), num_11);
    }
    else
    {
        // 반시계 방향
        int num_12 = wheels[wheel_num][0];
        wheels[wheel_num].erase(wheels[wheel_num].begin());
        wheels[wheel_num].push_back(num_12);
    }
}

void Rotate()
{
    while (K-- > 0)
    {
        // direct 1 : 시계, -1 : 반시계
        int wheel_num; int direct;
        cin >> wheel_num >> direct;


        Change(wheel_num, direct);
        
        // 다른 톱니 돌리기 

        // 왼쪽 톱니
        for (int i = 1; i <= 3; i++)
        {
            int left_wheel_num = wheel_num - i;
            if (left_wheel_num == 0) break;

            int previous_wheel_num = left_wheel_num + 1;

            int left_wheel_direct = direct;

            if (i % 2 == 1) left_wheel_direct *= -1;
            int previous_wheel_direct = left_wheel_direct * -1;

            // 극이 서로 다를 경우
            if (wheels[left_wheel_num][2] != wheels[previous_wheel_num][6 + previous_wheel_direct])
            {
                Change(left_wheel_num, left_wheel_direct);
            }
            // 극이 같을 경우 회전 정지
            else
            {
                break;
            }
        }

        // 오른쪽 톱니
        for (int i = 1; i <= 3; i++)
        {
            int right_wheel_num = wheel_num + i;
            if (right_wheel_num == 5) break;

            int previous_wheel_num = right_wheel_num - 1;

            int right_wheel_direct = direct;

            if (i % 2 == 1) right_wheel_direct *= -1;
            int previous_wheel_direct = right_wheel_direct * -1;

            // 극이 서로 다를 경우
            if (wheels[right_wheel_num][6] != wheels[previous_wheel_num][2 + previous_wheel_direct])
            {
                Change(right_wheel_num, right_wheel_direct);
            }
            // 극이 같을 경우 회전 정지
            else
            {
                break;
            }
        }

    }
}

void Cal()
{
    int score = 0;
    score += wheels[1][0] == 1 ? 1 : 0;
    score += wheels[2][0] == 1 ? 2 : 0;
    score += wheels[3][0] == 1 ? 4 : 0;
    score += wheels[4][0] == 1 ? 8 : 0;

    cout << score;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 맞닿은 극이 다르면, 왼쪽이 돌아갈 때 오른쪽은 왼쪽의 반대 방향으로 돌아간다.

    for (int i = 1; i <= 4; i++) 
    {
        string wheel;
        cin >> wheel;

        for (int j = 0; j < 8; j++)
        {
            if (wheel[j] == '1') wheels[i].push_back(1);
            else wheels[i].push_back(0);
        }
        
    }


    cin >> K;
    Rotate();
    Cal();
    
    return 0;
}

