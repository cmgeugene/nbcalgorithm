#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool IsValid(int row, int col, vector<int>& queens) {
    for (int prev_row = 0; prev_row < row; prev_row++) {
        int prev_col = queens[prev_row];

        // 같은 열에 퀸이 있는 경우
        if (col == prev_col) return false;

        // 같은 대각선에 퀸이 있는 경우
        if (abs(col - prev_col) == abs(row - prev_row)) return false;
    }
    return true;
}

// DFS를 이용한 백트래킹
void DFS(int row, int n, vector<int>& queens, int& answer) {
    if (row == n) {
        answer++; // n개의 퀸을 성공적으로 배치
        return;
    }

    for (int col = 0; col < n; col++) {
        if (IsValid(row, col, queens)) {
            queens[row] = col;
            DFS(row + 1, n, queens, answer);
        }
    }
}

int solution(int n) {
    int answer = 0;
    // queens[i] = i행에 놓인 퀸의 열
    vector<int> queens(n); 
    DFS(0, n, queens, answer);
    return answer;
}
