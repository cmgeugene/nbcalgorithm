#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    // e 기준으로 targets 정렬
    sort(targets.begin(), targets.end(), compare);
    
    int lastshot = INT_MIN;
    for(auto& target : targets)
    {
        if(target[0] >= lastshot)
        {
            answer++;
            lastshot = target[1];
        }
    }
    return answer;
}