#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

int N;
unordered_map<string, string> _map;
unordered_set<string> _names;
priority_queue<string, vector<string>> pq;

int main()
{
    cin >> N;



    for (int i = 0; i < N; i++)
    {
        string name; string status;

        cin >> name >> status;
        _map[name] = status;
        _names.insert(name);


    }

    for (auto name : _names)
    {
        if (_map[name] == "enter")
        {
            pq.push(name);
        }
    }

    while (!pq.empty())
    {
        string name = pq.top();
        pq.pop();
        cout << name << '\n';
    }

    return 0;
}

