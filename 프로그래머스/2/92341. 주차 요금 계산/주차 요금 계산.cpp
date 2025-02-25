#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

int convert_minutes(string s)
{
    int hour = stoi(s.substr(0, 2));
    int min = stoi(s.substr(3, 2));
    return hour * 60 + min;
    
    
}

struct cmp
{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2)
    {
        return p1.first > p2.first;
    }
};

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> car_min;
    map<string, int> car_in_list;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    for(int i = 0; i < records.size(); i++)
    {
        string str = records[i];
        string hour_min = str.substr(0, 5);
        string car_number = str.substr(6, 4);
        string mode = str.substr(11, 2);
        
        int total_min = convert_minutes(hour_min);
        
        if(mode[0] == 'I')
        {
            car_in_list[car_number] = total_min;
        }
        else
        {
            int parking_min = total_min - car_in_list[car_number];
            car_min[car_number] += parking_min;
            car_in_list[car_number] = -1;
        }
        
    }
    
    // IN만 하고 OUT이 없는 케이스
    for(auto& kv : car_in_list)
    {
        if(kv.second != -1)
        {
            string car_number = kv.first;
            string last_time = "23:59";
            int total_min = convert_minutes(last_time);
            
            int parking_min = total_min - car_in_list[car_number];
            car_min[car_number] += parking_min;
            
        }
        
        int parking_min = car_min[kv.first];
        int fee = fees[1];
        if(parking_min > fees[0])
        {
            // 기본 시간 초과
            fee += (parking_min - fees[0]) / fees[2] * fees[3];

            if((parking_min - fees[0]) % fees[2])
            {
                fee += fees[3];
            }
        }
        pq.push({stoi(kv.first), fee});
    }
    
    while(!pq.empty())
    {
        auto a = pq.top();
        pq.pop();
        cout << a.first << '\n';
        answer.push_back(a.second);
    }
    
    return answer;
}