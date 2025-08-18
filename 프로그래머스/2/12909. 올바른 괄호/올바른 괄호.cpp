#include <string>
#include <queue>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    if(s[0] == ')') return false;

    queue<char> que;
    
    for(char t : s)
    {
        if(t == '(') que.push(t);
        else if(t == ')') 
        {
            if(!que.empty()) que.pop();
            else return false;
        }
            
    }
    
    
    return que.empty();
}