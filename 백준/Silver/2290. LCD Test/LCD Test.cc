#include <iostream>
#include <string>
using namespace std;

int s;
string n;

int width, height;


int main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> s >> n;
    width = s + 2;
    height = 2 * s + 3;

    // 가운데 줄이 없는 숫자 : 1, 7, 0
    // 위 줄이 없는 숫자 : 1, 4
    // 아랫줄이 없는 숫자 : 1, 4, 7


    for (int i = 1; i <= height; i++)
    {
        bool top_flag = false;

        bool middle_flag = false;
        bool bottom_flag = false;

        if (i == 1)
        {
            top_flag = true;
        }
        else if (i == 2 + s)
        {
            middle_flag = true;
        }
        else if (i == height)
        {
            bottom_flag = true;
        }

        for (auto& c : n)
        {
            if (c == '1')
            {
                if (top_flag || middle_flag || bottom_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << " ";
                }
                else
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << "|";
                }
            }
            else if (c == '2')
            {
                if (top_flag || middle_flag || bottom_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else
                {
                    if (i > 1 && i < s + 2)
                    {
                        // 상위
                        cout << " ";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                    else
                    {
                        // 하위
                        cout << "|";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << " ";
                    }
                }
            }
            else if (c == '3')
            {
                if (top_flag || middle_flag || bottom_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else
                {
                    // 상위&하위
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << "|";
                }
            }
            else if (c == '4')
            {
                if (top_flag || bottom_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << " ";
                }
                else if (middle_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else
                {
                    if (i > 1 && i < s + 2)
                    {
                        // 상위
                        cout << "|";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                    else
                    {
                        // 하위
                        cout << " ";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                }
            }
            else if (c == '5')
            {
                if (top_flag || middle_flag || bottom_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else
                {
                    if (i > 1 && i < s + 2)
                    {
                        // 상위
                        cout << "|";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << " ";
                    }
                    else
                    {
                        // 하위
                        cout << " ";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                }
            }
            else if (c == '6')
            {
                if (top_flag || middle_flag || bottom_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else
                {
                    if (i > 1 && i < s + 2)
                    {
                        // 상위
                        cout << "|";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << " ";
                    }
                    else
                    {
                        // 하위
                        cout << "|";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                }
            }
            else if (c == '7')
            {
                if (top_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else if (middle_flag || bottom_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << " ";
                }
                else
                {
                    if (i > 1 && i < s + 2)
                    {
                        // 상위
                        cout << " ";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                    else
                    {
                        // 하위
                        cout << " ";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                }
            }
            else if (c == '8')
            {
                if (top_flag || bottom_flag || middle_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else
                {
                    // 상위&하위
                    cout << "|";
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << "|";

                }
            }
            else if (c == '9')
            {
                if (top_flag || bottom_flag || middle_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else
                {
                    if (i > 1 && i < s + 2)
                    {
                        // 상위
                        cout << "|";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                    else
                    {
                        // 하위
                        cout << " ";
                        for (int j = 0; j < s; j++) cout << " ";
                        cout << "|";
                    }
                }
            }
            else if (c == '0')
            {
                if (top_flag || bottom_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << "-";
                    cout << " ";
                }
                else if (middle_flag)
                {
                    cout << " ";
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << " ";
                }
                else
                {
                    // 상위&하위
                    cout << "|";
                    for (int j = 0; j < s; j++) cout << " ";
                    cout << "|";
                }
            }

            cout << " ";
            
        }
        cout << '\n';
    }

    

    return 0;
}