#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

string password;

void input()
{
    cin >> password;

}

bool is_aeiou(char c)
{
    return c == 'a' || c == 'e' || c == 'i' ||
        c == 'o' || c == 'u';
}

void sol()
{
    if (password == "end") return;

    char three_char[3] = { password[0], };
    bool aeiou = is_aeiou(password[0]);
    
    for (int i = 1; i < password.size(); i++)
    {
        // aeiou 포함되어있는지 확인
        if(!aeiou && is_aeiou(password[i]))
        {
            aeiou = true;
        }

        // 연속 3개 자음 or 모음인지 확인
        three_char[i % 3] = password[i];
        if (i >= 2)
        {
            if (is_aeiou(three_char[0]) == is_aeiou(three_char[1]) &&
                is_aeiou(three_char[1]) == is_aeiou(three_char[2]) &&
                is_aeiou(three_char[2]) == is_aeiou(three_char[0]))
            {
                aeiou = false;
                break;
            }
        }


        // 같은 글자가 연속인지
        if (password[i] == password[i - 1])
        {
            if (password[i] == 'o' || password[i] == 'e') continue;
            aeiou = false;
            break;
        }


    }

    if (!aeiou)
    {
        cout << "<" << password << "> is not acceptable." << '\n';
    }
    else
    {
        cout << "<" << password << "> is acceptable." << '\n';
    }


    input();
    sol();
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    input();
    sol();

    
    return 0;
}

