#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int remainsubs = k;
    stack<char> answerstack;
    
    for(char digit : number)
    {
        while(!answerstack.empty() && remainsubs > 0 && answerstack.top() < digit)
        {
            answerstack.pop();
            remainsubs--;
        }
        answerstack.push(digit);
    }
    
    while(remainsubs > 0)
    {
        answerstack.pop();
        remainsubs--;
    }
    
    while(!answerstack.empty())
    {
        answer += answerstack.top();
        answerstack.pop();
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}