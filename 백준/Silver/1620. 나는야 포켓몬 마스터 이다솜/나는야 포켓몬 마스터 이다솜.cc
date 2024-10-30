#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<string, int> name_num;
string num_name[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string name;
        cin >> name;
        name_num[name] = i;
        num_name[i] = name;
    }

    for (int i = 0; i < M; i++)
    {
        string line;
        cin >> line;
        if (isdigit(line[0]))
        {
            cout << num_name[stoi(line)] << '\n';
        }
        else
        {
            cout << name_num[line] << '\n';
        }

    }

    return 0;
}

