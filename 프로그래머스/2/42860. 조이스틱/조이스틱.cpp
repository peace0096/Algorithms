#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

int solution(string name) {
    int answer = 0;
    int move = name.size() - 1; // 총 커서 이동 횟수. 최댓값은 왼쪽부터 오른쪽까지 모두 훏었을 때
    
    for (int i = 0; i < name.size(); i++)
    {
        char c = name[i];

        int change = min(c - 'A', 'Z' - c + 1);
        answer += change;

        int nextIdx = i + 1;
        while (nextIdx < name.size() && name[nextIdx] == 'A') nextIdx++;

        int left = name.size() - 1 - nextIdx + 1;

        // A를 기점으로, 왼쪽과 오른쪽의 최소 움직임을 구한다. 양끝 커서끼리 움직일 수도 있으므로 min을 때려서 양끝 커서를 넘어가는 것이 효율적인지, 아니면 쭉 직진하는게 효율적인지 판단한다.
        move = min(move, i + left + min(i, left));

    }
    answer += move;

    return answer;
}