#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}
    
int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    int wanhoA = scores[0][0], wanhoB = scores[0][1];
    int wanhoSum = wanhoA + wanhoB;
    
    sort(scores.begin(), scores.end(), compare);
    
    int maxB = 0;
    bool excluded = false;
    int rank = 1;
    
    for(auto& score : scores)
    {
        int a = score[0];
        int b = score[1];
        
        // 앞의 사원보다 a와 b 둘 다 낮음 -> 인센티브 제외
        if(b < maxB)
        {
            if(a == wanhoA && b == wanhoB)
            {
                excluded = true;
                break;
            }
            continue;
        }
        // 완호보다 높은 점수 -> rank 증가
        if(a+b > wanhoSum) rank++;
        
        maxB = max(maxB,b);
    }
    
    return excluded? -1 : rank;
}