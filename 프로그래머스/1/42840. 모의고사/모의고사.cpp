#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> std1, std2, std3;
    vector<int> std2pattern = {1, 3, 4, 5};
    int score1 = 0, score2 = 0, score3 = 0, maxscore = 0;
    
    for(int i = 0; i < answers.size(); i++)
    {
        //1번 수포자 마킹
        std1.push_back(i % 5 + 1);
        //2번 수포자 마킹
        if(i % 2 == 0) { std2.push_back(2); }
        else if(i % 2 != 0)
        {
            if(i == 1) { std2.push_back(1); }
            else if( std2[i-2] == 1 ) { std2.push_back(3); }
            else if( std2[i-2] == 3 ) { std2.push_back(4); }
            else if( std2[i-2] == 4 ) { std2.push_back(5); }
            else if( std2[i-2] == 5 ) { std2.push_back(1); }
        }
        //3번 수포자 마킹
        if(i % 10 == 0 || i % 10 == 1) { std3.push_back(3); }
        else if(i % 10 == 2 || i % 10 == 3) { std3.push_back(1); }
        else if(i % 10 == 4 || i % 10 == 5) { std3.push_back(2); }
        else if(i % 10 == 6 || i % 10 == 7) { std3.push_back(4); }
        else if(i % 10 == 8 || i % 10 == 9) { std3.push_back(5); }
    }
    //채점
    for(int i = 0; i < answers.size() ; i++)
    {
        if(answers[i] == std1[i]) { score1++; }
        if(answers[i] == std2[i]) { score2++; }
        if(answers[i] == std3[i]) { score3++; }
    }
    maxscore = max({score1, score2, score3});
    if(maxscore == score1) { answer.push_back(1); }
    if(maxscore == score2) { answer.push_back(2); }
    if(maxscore == score3) { answer.push_back(3); }
    return answer;
}