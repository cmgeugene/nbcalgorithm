#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        stack<char> order;
        bool isOpen = false;
        for(char t : s)
        {
            if(t == '[' || t == '{' || t == '(')
            {
                isOpen = true;
                order.push(t);
            }
            else
            {
                if(t == ']' && order.top() == '[')
                {
                    order.pop();
                }
                if(t == '}' && order.top() == '{')
                {
                    order.pop();
                }
                if(t == ')' && order.top() == '(')
                {
                    order.pop();
                }
            }    
        }
        if(isOpen && order.empty())
        {
            answer++;
        }
        s.push_back(s[0]);
        s.erase(s.begin());
    }
    return answer;
}