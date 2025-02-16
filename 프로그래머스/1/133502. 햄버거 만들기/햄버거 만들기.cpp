#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> order;
    
    for(int i : ingredient)
    {
        order.push(i);
        if(order.size() >= 4)
        {
            vector<int> temp;
            for(int i = 0; i < 4; i++)
            {
                temp.push_back(order.top());
                order.pop();
            }
            if(temp[0] == 1 && temp[1] == 3 && temp[2] == 2 && temp[3] == 1)
            {
                answer++;
            }
            else for(int j = 3; j >= 0; j--)
            {
                order.push(temp[j]);
            }
        }
    }
    return answer;
}