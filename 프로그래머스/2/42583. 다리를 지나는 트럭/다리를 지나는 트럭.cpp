#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0;
    int currentload = 0;
    queue<int> truck_wait;
    // 트럭(무게), 들어간 시각
    queue<pair<int, int>> acrossing;
    for(int truck : truck_weights)
    {
        truck_wait.push(truck);
    }
    // 한 대가 다리를 건너는 데 걸리는 경과 시간 bridge_length
    // if(acrossing.front().second + bridge_length == time) pop()
    // if(currentload + truck_wait.front() <= weight) 다음 트럭올라갈 수 있음
    // if(truck.empty() && acrossing.empty()) return time;
    
    while(!truck_wait.empty() || !acrossing.empty())
    {
        time++;
        if(!acrossing.empty() && acrossing.front().second + bridge_length == time)
        {
            currentload -= acrossing.front().first;
            acrossing.pop();
        }
        if(!truck_wait.empty() && currentload + truck_wait.front() <= weight)
        {
            currentload += truck_wait.front();
            acrossing.push(make_pair(truck_wait.front(),time));
            truck_wait.pop();
        }
        if(truck_wait.empty() && acrossing.empty()) break;

    }
    answer = time;
    return answer;
}