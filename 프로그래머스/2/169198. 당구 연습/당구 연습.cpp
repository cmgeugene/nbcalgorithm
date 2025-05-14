#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int closestdist(int m, int n, int startX, int startY, vector<int>& ball)
{
    // y축 대칭
    int dist1 = (-1 * ball[0] - startX) * (-1 * ball[0] - startX) + (ball[1] - startY) * (ball[1] - startY);
    // x축 대칭
    int dist2 = (ball[0] - startX) * (ball[0] - startX) + (ball[1] - startY * -1) * (ball[1] - startY * -1);
    // y축 끝 대칭
    int dist3 = (2 * m - ball[0] - startX) * (2 * m - ball[0] - startX) + (ball[1] - startY) * (ball[1] - startY);
    // x축 끝 대칭
    int dist4 = (ball[0] - startX) * (ball[0] - startX) + (2 * n - ball[1] - startY) * (2 * n - ball[1] - startY);
    
    // 예외1 : 같은 x축에 있음
    if(ball[0] == startX)
    {
        if(startY > ball[1]) return min({dist1, dist3, dist4});
        if(startY < ball[1]) return min({dist1, dist2, dist3});
    }
            
    // 예외2 : 같은 y축에 있음
    if(ball[1] == startY)
    {
        if(startX > ball[0]) return min({dist2, dist3, dist4});
        if(startX < ball[0]) return min({dist1, dist2, dist4});
    }
    
    return min({dist1, dist2, dist3, dist4});
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    // ball[i] = {x,y} 일 때
    // y축 대칭 = {-x, y}
    // x축 대칭 = {x, -y}
    // y축 끝 대칭 = {m + (m-x), y}
    // x축 끝 대칭 = {x, n + (n - y)}
    
    for(auto& ball : balls)
    {
        int shot = closestdist(m, n, startX, startY, ball);
        answer.push_back(shot);
    }
    
    return answer;
}