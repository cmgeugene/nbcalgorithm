#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // 반복문의 반복 횟수를 구하는 문제
    int priority = 0;
    // 원래 인덱스 값을 같이 저장
    deque<pair<int, int>> tasks;
    for(int i = 0; i < priorities.size(); i++)
    {
        tasks.push_back({i, priorities[i]});
    }
    
    // 반복 한 번에 규칙 1~3 실행
    while(!tasks.empty())
    {
        // 1. 큐에서 프로세스 꺼냄
        priority = tasks.front().second;
        bool IsThereHigher = false; 
        deque<pair<int, int>>::iterator it;
        for(it = tasks.begin(); it != tasks.end(); it++)
        {
            // 2. 더 높은 우선순위 프로세스가 있으면 큐에 다시 넣기
            if(it->second > priority)
            {
                tasks.push_back(tasks.front());
                tasks.pop_front();
                IsThereHigher = true;
                break;
            }
        }
        // 3. 없으면 실행    
        if(!IsThereHigher)
        {
            if(tasks.front().first == location)
            {
                return answer + 1;
            }
            tasks.pop_front();
            answer++;
        }
    }
}