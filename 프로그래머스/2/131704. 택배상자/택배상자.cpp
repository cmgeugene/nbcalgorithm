#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> orderque;
    stack<int> subcon;
    queue<int> maincon;
    
    for(int i = 0; i < order.size(); i++)
    {
        maincon.push(i+1);
    }
    
    for(auto& package : order)
    {
        orderque.push(package);
    }
    
    while(!orderque.empty())
    {
        if(!maincon.empty() && maincon.front() == orderque.front())
        {
            maincon.pop();
            orderque.pop();
            answer++;
        }
        if(!subcon.empty() && subcon.top() == orderque.front())
        {
            subcon.pop();
            orderque.pop();
            answer++;
        }
        
        if(!maincon.empty() && maincon.front() != orderque.front())
        {
            subcon.push(maincon.front());
            maincon.pop();
        }
        
        if(!subcon.empty() && maincon.empty() && orderque.front() != subcon.top())
        {
            break;
        }
    }
    return answer;
}