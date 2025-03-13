#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> dq_prog;
    deque<int> dq_speeds;
    
    //벡터 큐에다 넣기
    for(int i = 0; i < speeds.size(); i++)
    {
        dq_prog.push_back(progresses[i]);
        dq_speeds.push_back(speeds[i]);
    }
    
    while(!dq_prog.empty())
    {
        int finished = 0;
        for(int i = 0; i < dq_prog.size(); i++)
        {
            if(dq_prog[i] < 100) dq_prog[i] += dq_speeds[i];
        }
        while(!dq_prog.empty() && dq_prog.front() >= 100)
        {
            dq_prog.pop_front();
            dq_speeds.pop_front();
            finished++;
        }
        if(finished > 0) answer.push_back(finished);
    }
    
    return answer;
}