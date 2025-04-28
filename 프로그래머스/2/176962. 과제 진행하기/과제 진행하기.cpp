#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int ToMinute(string minute) {
    int hour = stoi(minute.substr(0, 2));
    int min = stoi(minute.substr(3, 2));
    return (hour * 60) + min;
}

struct tasks {
    string name;
    int start;
    int time;

    bool operator>(const tasks& other) const {
        return start > other.start;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<tasks, vector<tasks>, greater<tasks>> pq;
    stack<tasks> temp;

    // plans를 큐에 넣기
    for (auto& plan : plans) {
        pq.push({plan[0], ToMinute(plan[1]), stoi(plan[2])});
    }

    // 현재 시간은 첫 번째 과제의 시작 시간
    int now = pq.top().start;

    while (!pq.empty() || !temp.empty()) {
        if (!pq.empty()) {
            tasks current = pq.top();
            pq.pop();

            // 다음 과제 시작 시간
            int nextStartTime = pq.empty() ? 1e9 : pq.top().start;

            // 과제 시작 전까지 스택에 있는 과제 처리
            while (!temp.empty() && now < current.start) {
                tasks paused = temp.top();
                temp.pop();

                if (now + paused.time <= current.start) {
                    now += paused.time;
                    answer.push_back(paused.name);
                } else {
                    paused.time -= (current.start - now);
                    now = current.start;
                    temp.push(paused);
                    break;
                }
            }

            // 만약 now가 current 시작 시간보다 작으면 맞춰주기
            if (now < current.start) {
                now = current.start;
            }

            // 현재 과제를 완료할 수 있는지 확인
            if (now + current.time <= nextStartTime) {
                now += current.time;
                answer.push_back(current.name);
            } else {
                // 시간 부족 -> current를 temp에 push
                current.time -= (nextStartTime - now);
                now = nextStartTime;
                temp.push(current);
            }
        } 
        else {
            // 예정된 과제는 없고, temp 과제만 남은 경우
            while (!temp.empty()) {
                answer.push_back(temp.top().name);
                temp.pop();
            }
        }
    }
    return answer;
}
