#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int> score = {{'R', 0}, {'T', 0},{'C',0},{'F',0},{'J',0},{'M',0},{'A',0},{'N',0}};
    for(int i = 0; i< survey.size(); i++)
    {
        switch(choices[i])
        {
            case 1: score[survey[i][0]] += 3; break;
            case 2: score[survey[i][0]] += 2; break;
            case 3: score[survey[i][0]] += 1; break;
            case 4: score[survey[i][0]] += 0; break;
            case 5: score[survey[i][1]] += 1; break;
            case 6: score[survey[i][1]] += 2; break;
            case 7: score[survey[i][1]] += 3; break;
            default: break;
        }
    }
    score['R'] >= score['T'] ? answer += 'R' : answer += 'T';
    score['C'] >= score['F']? answer += 'C' : answer += 'F';
    score['J'] >= score['M']? answer += 'J' : answer += 'M';
    score['A'] >= score['N']? answer += 'A' : answer += 'N';
    return answer;
}