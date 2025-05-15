#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽
vector<int> dr = {-1, 0, 1, 0};
vector<int> dc = { 0, 1, 0, -1};

int takecycle(vector<string>& map, vector<vector<vector<bool>>>& visited, int startX, int startY, int direction)
{
    int count = 0;
    int rows = map.size();
    int cols = map[0].size();
    // current row, col, direction
    int cr = startX, cc = startY, cd = direction;
    
    while(true)
    {
        if(visited[cr][cc][cd]) break;
        
        // 방문 처리, 카운트(길이) 증가
        visited[cr][cc][cd] = true;
        count++;
        
        // 방향 변경
        char cell = map[cr][cc];
        if(cell == 'L')
            cd = (cd + 3) % 4;
        else if(cell == 'R')
            cd = (cd + 1) % 4;
        
        // cd에 맞게 이동(토러스 래핑)
        cr = (cr + dr[cd] + rows) % rows;
        cc = (cc + dc[cd] + cols) % cols;
    }
    
    return count;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<string> map = grid;
    
    // 경로 기록 방향 4가지까지 포함하도록 초기화
    vector<vector<vector<bool>>> visited(
        rows, 
        vector<vector<bool>>(
            cols, 
            vector<bool>(4, false)
        )
    );
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            for(int d = 0; d < 4; d++)
            {
                int cyclelength = takecycle(map, visited, i, j, d);
                if(cyclelength > 0) answer.push_back(cyclelength);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}