#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> score;
    
    for(int i = 0; i < numbers.size(); i++) {
        score.push_back(to_string(numbers.at(i)));
    }
    sort(score.begin(), score.end(), compare);
    
    for(int i = 0; i < score.size(); i++) {
        answer += score.at(i);
    }
    if(answer[0] == '0') answer = "0";
    
    return answer;
}