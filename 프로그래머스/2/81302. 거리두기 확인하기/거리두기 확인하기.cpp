#include <string>
#include <vector>
#include <queue>

using namespace std;

bool IsValid(const vector<string>& room, int row, int col)
{
    queue<pair<int, int>> bfsQ;
    bfsQ.push({row,col});
    // 매개변수로 주어진 row와 col에서의 거리를 담을 방문배열. 0으로 초기화
    vector<vector<int>> distance(5, vector<int>(5, 0));
    
    // 탐색 방향 순서대로 하 상 우 좌
    int drow[] = {1, -1, 0, 0};
    int dcol[] = {0, 0, 1, -1};
    
    while(!bfsQ.empty())
    {
        pair<int, int> parti = bfsQ.front();
        int _row = parti.first;
        int _col = parti.second;
        bfsQ.pop();
        
        for(int k = 0; k < 4; k++)
        {
            int newrow = parti.first + drow[k];
            int newcol = parti.second + dcol[k];
            
            //범위를 넘어가거나, 방문한 적이 있는 곳이면 패스, 처음 위치면 패스
            if(newrow < 0 || newrow >= 5 || newcol < 0 || newcol >= 5) continue;
            if(distance[newrow][newcol] != '0' && (newrow == row && newcol == col)) continue;
            
            // 거리 더하기
            int newdistance = distance[_row][_col] + 1;
            // 맨햍은 거리 2 초과면 패스
            if(newdistance > 2) continue;
            
            if(room[newrow][newcol] == 'X') continue;
            if(room[newrow][newcol] == 'P') return false;
            
            distance[newrow][newcol] = newdistance;
            bfsQ.push({newrow, newcol});
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& room : places) 
    {
        bool approved = true;
        for (int i = 0; i < 5 && approved; i++) {
            for (int j = 0; j < 5 && approved; j++) {
                if (room[i][j] == 'P') {
                    if (!IsValid(room, i, j)) {
                        approved = false;
                        break;
                    }
                }
            }
        }
        answer.push_back(approved ? 1 : 0);
    }

    return answer;
}