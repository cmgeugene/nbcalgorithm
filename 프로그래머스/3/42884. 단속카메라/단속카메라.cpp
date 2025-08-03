#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 나간 지점 오름차순 정렬
bool compare(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    
    int lastcamera = INT_MIN;
    for(vector<int>& route : routes)
    {
        if(route[0] > lastcamera)
        {
            answer++;
            lastcamera = route[1];
        }
    }
    
    return answer;
}