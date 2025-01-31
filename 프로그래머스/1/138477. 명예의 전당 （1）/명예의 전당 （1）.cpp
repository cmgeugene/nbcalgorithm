#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

vector<int> solution(int k, vector<int> scores) {
    vector<int> answer;
    vector<int> honor;
    for(int score : scores)
    {
        if(honor.size() < k)    // k일차 전까지
        {
            honor.push_back(score);
            sort(honor.begin(), honor.end(), compare);
            answer.push_back(honor.back());
        }
        else if(honor.size() == k) // k일 이후
        {
            sort(honor.begin(), honor.end(), compare);
            if(score > honor.back())  // 명예의 전당에 들 수 있을 때
            {
                honor.pop_back();
                honor.push_back(score);
                sort(honor.begin(), honor.end(), compare);
                answer.push_back(honor.back());
            }
            else // (score <= honor[k-1]) 명예의 전당에 들 수 없을 떄
            {
                answer.push_back(honor.back());
            }
        }
    }
    return answer;
}