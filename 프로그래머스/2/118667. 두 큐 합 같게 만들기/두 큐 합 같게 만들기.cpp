#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long onesum = 0, twosum = 0, count = 0, countlimit;
    queue<int> que1, que2;
    
    for(int q : queue1)
    {
        onesum += q;
        que1.push(q);
    }
    for(int q : queue2)
    {
        twosum += q;
        que2.push(q);
    }
    
    long long goal = (onesum + twosum) / 2;
    countlimit = (queue1.size() + queue2.size()) * 2;
    int queue1max = *max_element(queue1.begin(), queue1.end());
    int queue2max = *max_element(queue2.begin(), queue2.end());
    if (queue1max > goal || queue2max > goal)
    {
        return answer;
    }
    
    while(twosum != goal && onesum != goal)
    {
        if(count > countlimit)
        {
            return -1;
        }
        if(que1.empty() || que2.empty())
        {
            return -1;
        }
        
        if(!que1.empty() && onesum > twosum)
        {
            que2.push(que1.front());
            twosum += que1.front();
            onesum -= que1.front();
            que1.pop();
            count++;
        }
        
        if(!que2.empty() && twosum > onesum)
        {
            que1.push(que2.front());
            onesum += que2.front();
            twosum -= que2.front();
            que2.pop();
            count++;
        }
        
        if(twosum == goal && onesum == goal)
        {
            return count;
        }
    }
    answer = count;
    return answer;
}