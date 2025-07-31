#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

long long sumsquared(priority_queue<int>& pque)
{
    long long sum = 0;
    while(!pque.empty())
    {
        int top = pque.top();
        sum += (long long)top * top;
        pque.pop();
    }
    return sum;
}

long long solution(int n, vector<int> works) {

    int lefthour = n;
    priority_queue<int> pque;
    
    for(auto& work : works)
    {
        pque.push(work);
    }
    
    while(lefthour > 0)
    {
        int currentwork = pque.top();
        pque.pop();
        
        if(currentwork == 0) break;
        
        currentwork--;
        lefthour--;
        
        pque.push(currentwork);
    }
    
    return sumsquared(pque);
}