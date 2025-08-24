#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int N = board.size();
    int M = board[0].size();
    
    vector<vector<int>> change(N+1, vector<int>(M+1, 0));
    for(auto& effect : skill)
    {
        int type = effect[0] == 1 ? -1 : 1;
        int damage = effect[5];
        
        int r1 = effect[1], c1 = effect[2];
        int r2 = effect[3], c2 = effect[4];
        
        change[r1][c1] += type * damage;
        change[r1][c2+1] += type * damage * -1;
        change[r2+1][c1] += type * damage * -1;
        change[r2+1][c2+1] += type * damage;
    }
    
    // 가로 더하기
    for(int i = 0; i < change.size(); i++)
    {
        for(int j = 1; j < change[0].size(); j++)
        {
            change[i][j] += change[i][j-1]; 
        }
    }
    
    // 세로 더하기
    for(int j = 0; j < change[0].size(); j++)
    {
        for(int i = 1; i < change.size(); i++)
        {
            change[i][j] += change[i-1][j]; 
        }
    }
    
    // 합치기
    int answer = 0;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            board[i][j] += change[i][j];
            if(board[i][j] >= 1) answer++;
        }
    }
    return answer;
}