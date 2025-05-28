#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct ftask
{
    int duration;
    int requesttime;
    int no;
    
    bool operator<(const ftask& other) const
    {
        if(duration == other.duration)
        {
            if(requesttime == other.requesttime)
            {
                return no > other.no;
            }
            return requesttime > other.requesttime;
        }
        return duration > other.duration;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    // 요청시간 기준 정렬
    sort(jobs.begin(), jobs.end());
    
    queue<ftask> waitq;
    for(int i = 0; i < n; i++)
    {
        waitq.push({jobs[i][1], jobs[i][0], i});
    }
    
    priority_queue<ftask> readyq;
    int completed = 0;
    int currenttime = 0;
    int totalturnaround = 0;
    
    while(completed < n)
    {
        while(!waitq.empty() && waitq.front().requesttime <= currenttime)
        {
            readyq.push(waitq.front());
            waitq.pop();
        }
        
        if(!readyq.empty())
        {
            ftask task = readyq.top();
            readyq.pop();
            
            currenttime += task.duration;
            totalturnaround += (currenttime - task.requesttime);
            completed++;
        }
        else
        {
            if(!waitq.empty())
            {
                currenttime = waitq.front().requesttime;
            }
        }
    }
    
    
    answer = totalturnaround / n;
    return answer;
}