#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = 0, y = 0;
    int H = park.size();
    int W = park[0].size();
    
    // 시작 위치 찾기
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (park[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
    }
    
    for (const string& route : routes) {
        char dir = route[0];
        int steps = stoi(route.substr(2));
        
        int dx = 0, dy = 0;
        if (dir == 'E') dy = 1;
        else if (dir == 'W') dy = -1;
        else if (dir == 'S') dx = 1;
        else if (dir == 'N') dx = -1;
        
        int new_x = x + dx * steps;
        int new_y = y + dy * steps;
        
        // 공원 범위 검사
        if (new_x < 0 || new_x >= H || new_y < 0 || new_y >= W)
            continue;
        
        // 장애물 검사
        bool blocked = false;
        for (int i = 1; i <= steps; ++i) {
            int check_x = x + dx * i;
            int check_y = y + dy * i;
            if (park[check_x][check_y] == 'X') {
                blocked = true;
                break;
            }
        }
        
        if (!blocked) {
            x = new_x;
            y = new_y;
        }
    }
    
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}