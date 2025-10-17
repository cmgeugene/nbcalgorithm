#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, float>& a, pair<int, float>& b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> failed_users(N+2, 0);
    int remain_users = stages.size();
    
    // 각 스테이지에 멈춘 사용자 수
    vector<int> challengers(N+2, 0);
    for(int stage : stages) challengers[stage]++;
    
    // 스테이지 순회
    vector<pair<int, float>> fail_rate;
    for(int i = 1; i <= N; i++)
    {
        if(remain_users == 0)
        {
            fail_rate.push_back({i, 0});
        }    
        else
        {
            float rate = (float)challengers[i] / remain_users;
            fail_rate.push_back({i, rate});
        }
        remain_users -= challengers[i];
    }
    
    // 정렬 후 추가
    sort(fail_rate.begin(), fail_rate.end(), compare);
    for(auto& rate : fail_rate)
    {
        answer.push_back(rate.first);
    }
    
    return answer;
}