#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dist(int a, int b, int x, int y)
{
    return abs(a - x) + abs(b - y);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int distance = dist(x,y,r,c);
    if(distance > k || (k - distance) % 2 == 1) return "impossible";
    
    int step = 0;
    
    // 사전순이므로 d, l, r, u 순으로 검사
    
    int dx[4] = {  1,  0,  0, -1 };
    int dy[4] = {  0, -1,  1,  0 };
    char dc[4]= { 'd','l','r','u' };
    string path = "";
    int current_x = x, current_y = y;
    
    for(step = 0; step < k; step++)
    {
        for(int dir = 0; dir < 4; dir++)
        {
            int new_x = current_x + dx[dir];
            int new_y = current_y + dy[dir];
            if(new_x < 1 || new_x > n || new_y < 1 || new_y > m) continue;
            
            int remaindist = k - (step + 1);
            int currentdist = dist(r,c,new_x,new_y);
            
            if (currentdist <= remaindist && ((remaindist - currentdist) & 1) == 0) 
            {
                path.push_back(dc[dir]);
                current_x = new_x; current_y = new_y;
                break;
            }
            
        }
    }
    
    return path;
}