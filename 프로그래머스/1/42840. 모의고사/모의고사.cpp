#include <string>
#include <vector>

//12345
//21232425
//3311224455
using namespace std;

vector<int> solution(vector<int> answers) {
    int one[] = {1,2,3,4,5};            //5
    int two[] = {2,1,2,3,2,4,2,5};      //8
    int three[] = {3,3,1,1,2,2,4,4,5,5};//10
    
    int score[] = {0,0,0};
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        if(answers.at(i) == one[s1]) {
            score[0]++;
        }
        if(answers.at(i) == two[s2]) {
            score[1]++;
        }
        if(answers.at(i) == three[s3]) {
            score[2]++;
        }
        if(s1 == 4) {
            s1=0;
        }
        else s1++;
           
        if(s2 == 7) {
            s2=0;
        }
        else s2++;
        
        if(s3 == 9) {
            s3=0;
        }
        else s3++;
    }
    vector<int> answer;
    answer.push_back(1);
    
    for(int i = 1; i < 3; i++) {
        if(score[answer.at(0)-1] == score[i]) {
            answer.push_back(i+1);
        }
        else if(score[answer.at(0)-1] < score[i]) {
            answer.clear();
            answer.push_back(i+1);
        }
    }
    return answer;
}