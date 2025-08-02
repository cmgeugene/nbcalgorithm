#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map(n+1, vector<int>(m+1, 0));
    
    // map에 물웅덩이 표시
    for(vector<int>& puddle : puddles)
    {
        int puddle_row = puddle[0];
        int puddle_col = puddle[1];
        
        map[puddle_col][puddle_row] = -1;
    }
    
    // 출발 전 초기화
    map[1][1] = 1;
    
    // 출발
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= m; col++)
        {
            if(col == 1 && row == 1) continue;
            
            // 목적지가 물웅덩이(-1) 아니면 왼쪽과 아래쪽 값 더하기
            if(map[row][col] != -1)
            {
                int up = map[row-1][col] == -1 ? 0 : map[row-1][col];
                int left = map[row][col-1] == -1 ? 0 : map[row][col-1];
                
                map[row][col] = (up + left) % 1000000007; 
            }
        }
    }
    answer = map[n][m];
    return answer % 1000000007;
}