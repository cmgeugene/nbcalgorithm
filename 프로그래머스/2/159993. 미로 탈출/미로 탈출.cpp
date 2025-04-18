#include <string>
#include <vector>
#include <queue>

using namespace std;

int pathfind(vector<string>& maps, char start, char goal)
{
    // 맵의 크기
    int rows = maps.size(), cols = maps[0].size();
    // start - goal 거리 저장할 벡터이면서 동시에 방문배열
    vector<vector<int>> dist(rows, vector<int>(cols, 0));
    
    // 4방향 이동
    int drow[] = {1, -1, 0, 0};
    int dcol[] = {0, 0, 1, -1};
    
    // 시작, 목표 좌표 {row, col}
    pair<int, int> posS = {0, 0}, posG = {0, 0};
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(maps[i][j] == start) posS = {i, j};
            if(maps[i][j] == goal) posG = {i, j};
        }
    }
    
    queue<pair<int, int>> bfsq;
    bfsq.push(posS);
    dist[posS.first][posS.second] = 1;
    
    // 시작 - 레버 거리 구하기
    while(!bfsq.empty())
    {
        pair<int, int> current = bfsq.front();
        bfsq.pop();
        
        // 4방향 순회
        int row = current.first, col = current.second;
        for(int k = 0; k < 4; k++)
        {
            int newrow = row + drow[k];
            int newcol = col + dcol[k];
            
            if(newrow >= rows || newrow < 0 || newcol >= cols || newcol < 0) continue;
            if(maps[newrow][newcol] == 'X') continue;
            if(dist[newrow][newcol] != 0) continue;
            
            dist[newrow][newcol] = dist[row][col] + 1;
            if(maps[newrow][newcol] == goal) return dist[newrow][newcol] -1; 
            bfsq.push({newrow, newcol});
            
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    int SL = pathfind(maps, 'S', 'L');
    int LE = pathfind(maps, 'L', 'E');
    if(SL == -1 || LE == -1) return -1;
    return SL + LE;
}