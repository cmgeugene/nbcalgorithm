#include <string>
#include <vector>

using namespace std;

bool checkWin(vector<string>& board, char symbol)
{
    int n = 3;
    // 가로 빙고 확인
    for(int i = 0; i < n; i++)
    {
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return true;
        }
    }
    // 세로 빙고 확인
    for(int j = 0; j < n; j++)
    {
        if(board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
        {
            return true;
        }
    }
    // 대각선 빙고 확인
    if(board[1][1] == symbol)
    {
        if(board[0][0] == symbol && board[2][2] == symbol)
        {
            return true;
        }
        else if(board[2][0] == symbol && board[0][2] == symbol)
        {
            return true;
        }
    }
    return false;
}

int solution(vector<string> board) {
    int answer = 0;
    // OX 개수 세기
    // 1. 3개가 만들어졌는데 계속 진행
    // 2. 개수 차이가 2 이상일 때
    int numo = 0, numx = 0;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 'O') numo++;
            else if(board[i][j] == 'X') numx++;
        }
    }
    
    bool oWins = checkWin(board, 'O');
    bool xWins = checkWin(board, 'X');
    
    // 시작조차 안한 경우
    if(numo == 0 && numx == 0) return 1;
    // 게임이 결판이 난 경우
    if(oWins && !xWins)
    {
        if(numo - numx == 1) return 1;
    }
    else if(!oWins && xWins)
    {
        if(numo == numx) return 1;
    }
    // 결판이 안 난 경우
    if(!oWins && !xWins)
    {
        int diff = numo - numx;
        if(0 <= diff && diff < 2) return 1;
    }
    return answer;
}