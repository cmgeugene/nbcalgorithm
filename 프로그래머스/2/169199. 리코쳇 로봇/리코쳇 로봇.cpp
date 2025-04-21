#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> gostraight(pair<int, int> current, int dir, vector<string>& board) 
{
    int r = current.first;
    int c = current.second;
    int rows = board.size();
    int cols = board[0].size();
    
    switch(dir) 
    {
        case 0: // 상
            while (r > 0 && board[r-1][c] != 'D') 
            {
                r--;
            }
            break;
            
        case 1: // 하
            while (r < rows - 1 && board[r+1][c] != 'D') 
            {
                r++;
            }
            break;
            
        case 2: // 좌
            while (c > 0 && board[r][c-1] != 'D') 
            {
                c--;
            }
            break;
            
        case 3: // 우
            while (c < cols - 1 && board[r][c+1] != 'D') 
            {
                c++;
            }
            break;
        default:
            return {-1, -1};
        break;
    }
    return {r, c};
}


int solution(vector<string> board) {
    int answer = -1;
    int movecount = 0;
    // 최소 이동이니까 BFS?
    // 방문배열이 필요할까? 부딪힐 때까지 이동하다보니 지나온 칸을 지나는 경우가 있다
    // 멈춘 칸을 추가하자
    queue<pair<int,int>> bfsq;
    int rows = board.size(), cols = board[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 'R') 
            {
                bfsq.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    while(!bfsq.empty())
    {
        pair<int, int> curr = bfsq.front();
        bfsq.pop();
        
        if(board[curr.first][curr.second] == 'G')
        {
            return dist[curr.first][curr.second];
        }
        
        // 4방향 직진
        for(int k = 0; k < 4; k++)
        {
            pair<int, int> temp = gostraight(curr, k, board);
            if(dist[temp.first][temp.second] == -1)
            {
                dist[temp.first][temp.second] = dist[curr.first][curr.second] + 1;
                bfsq.push(temp);    
            }
        }
    }
    return answer;
}