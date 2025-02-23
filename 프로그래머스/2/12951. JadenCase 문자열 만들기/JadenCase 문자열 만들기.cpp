#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = s;
    for(int i = 0; i < answer.size(); i++)
    {
        if(isupper(answer[i]))
        {
            if(answer[i-1] == ' ' || i == 0) answer[i];
            else
            {
                answer[i] = tolower(answer[i]);
            }
        }
        else if(islower(answer[i]))
        {
            if(answer[i-1] == ' ' || i == 0) answer[i] = toupper(answer[i]);
        }
    }
    return answer;
}