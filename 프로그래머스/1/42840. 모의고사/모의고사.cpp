#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> pattern01 = {1, 2, 3, 4, 5};
    vector<int> pattern02 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> pattern03 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> score(3);
    vector<int> answer;
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == pattern01[i%5]) score[0]++;
        if(answers[i] == pattern02[i%8]) score[1]++;
        if(answers[i] == pattern03[i%10]) score[2]++;
    }
    
    int max = *max_element(score.begin(), score.end());
    for(int i = 0; i < score.size(); i++)
    {
        if(max == score[i])
            answer.push_back(i+1);
    }
    
    return answer;
}