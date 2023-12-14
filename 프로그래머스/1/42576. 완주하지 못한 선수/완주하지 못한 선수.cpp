#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> runners;
    
    for(int i = 0; i < participant.size(); i++) {
        runners[participant.at(i)]++;
    }
    for(int i = 0; i < completion.size(); i++) {
        runners[completion.at(i)]++;
    }
    map<string, int>::iterator it;
    
    for(it = runners.begin(); it != runners.end(); it++) {
        int n = it->second;
        if(n % 2 == 1) {
            answer+=it->first;
        }
    }
    
    
    return answer;
}