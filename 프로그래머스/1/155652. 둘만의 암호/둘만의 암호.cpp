#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char check(char c, string skip, int index) 
{
    int count = 0;
    while (count < index) 
    {
        c++;
        if (c > 'z') c = 'a';
        if (find(skip.begin(), skip.end(), c) == skip.end()) 
        {
            count++;
        }
    }
    return c;
}

string solution(string s, string skip, int index) 
{
    string answer = "";
    
    for (char c : s)
    {
        answer.push_back(check(c, skip, index));
        
    }
    return answer;
}