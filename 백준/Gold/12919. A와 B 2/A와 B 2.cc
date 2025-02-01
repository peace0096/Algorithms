#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits.h>
using namespace std;

string S;
string T;

bool BF(string str)
{

    bool result = false;
    if (str == S) return true;
    if (str.size() <= S.size()) return false;

    // B 추가 후 뒤집은 케이스
    if (str[0] == 'B')
    {
        string temp = "";
        for (int i = str.size() - 1; i > 0; i--)
        {
            temp.push_back(str[i]);
        }
        if (BF(temp))
            result = true;
    }


    // A 추가한 케이스
    if (str[str.size() - 1] == 'A')
    {
        string temp = str;
        temp.erase(temp.end() - 1);

        if (BF(temp))
            result = true;
    }


    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> T;

    bool result = BF(T);

    if (result) cout << 1;
    else cout << 0;

    
    return 0;
}

