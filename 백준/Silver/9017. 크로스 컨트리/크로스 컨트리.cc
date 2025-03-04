#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
using namespace std;

int T = -1;
int N;
int arr[1001];

// 각 팀별 5번째 선수의 점수
int five_score[1001];

// 팀 점수 합산
int scores[1001];
int scores_num[1001];

// 몇명인지 집계
int team_num[1001];

int max_team = 1;

void input()
{
    if(T == -1) cin >> T;

    cin >> N;
    fill(five_score, five_score + N, 0);
    fill(scores, scores + N, 0);
    fill(scores_num, scores_num + N, 0);
    fill(team_num, team_num + N, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        max_team = max(max_team, arr[i]);
        team_num[arr[i]]++;
    }
    T--;
}


void sol()
{
    int score = 1;
    
    for (int i = 1; i <= N; i++)
    {
        // 팀 인원수 맞는지부터 봐라
        if (team_num[arr[i]] != 6) continue;
        scores_num[arr[i]]++;
        if (scores_num[arr[i]] <= 4)
        {
            scores[arr[i]] += score;
        }

        if (scores_num[arr[i]] == 5)
        {
            five_score[arr[i]] = score;
        }

        score++;

    }

    int winner = 0;
    for (int i = 1; i <= max_team; i++)
    {
        if (winner == 0 && team_num[i] == 6)
        {
            winner = i;
            continue;
        }


        if (team_num[i] == 6 && scores[winner] > scores[i])
        {
            winner = i;
        }
        else if(scores[winner] == scores[i])
        {
            winner = five_score[winner] > five_score[i] ? i : winner;
        }
    }



    cout << winner << '\n';


    if (T > 0)
    {
        input();
        sol();
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

