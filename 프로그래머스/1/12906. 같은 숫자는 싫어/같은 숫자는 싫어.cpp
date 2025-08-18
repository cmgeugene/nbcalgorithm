#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> que;
    
    que.push(arr[0]);
    for(int i = 1; i < arr.size(); i++)
    {
        if(que.back() != arr[i])
        {
            que.push(arr[i]);
        }
    }
    
    while(!que.empty())
    {
        answer.push_back(que.front());
        que.pop();
    }
    return answer;
}