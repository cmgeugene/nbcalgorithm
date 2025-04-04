#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int rows = maps.size();
    int cols = maps[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    queue<pair<int, int>> bfsq;
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(maps[i][j] != 'X' && !visited[i][j])
            {
                bfsq.push({i,j});
                visited[i][j] = true;
                int canstay = maps[i][j] - '0';
                
                //BFS 시작
                while(!bfsq.empty())
                {
                    pair<int, int> current = bfsq.front();
                    bfsq.pop();
                    
                    // 섬 상하좌우 탐색
                    int y = current.first;
                    int x = current.second;
                    for(int k = 0; k < 4; k++)
                    {
                        int newy = y + dy[k];
                        int newx = x + dx[k];
                        
                        //탐색 결과 큐에 저장
                        if(newx >= 0 && cols > newx && newy >= 0 && rows > newy && maps[newy][newx] != 'X' && !visited[newy][newx])
                        {
                            visited[newy][newx] = true;
                            canstay += maps[newy][newx] - '0';
                            bfsq.push({newy, newx});
                        }
                    }
                }
                answer.push_back(canstay);
            }
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.empty())
    {
        answer.push_back(-1);
    }
    return answer;
}