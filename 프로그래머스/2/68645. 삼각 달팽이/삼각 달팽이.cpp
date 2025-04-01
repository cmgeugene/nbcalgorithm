#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    // n * n 크기의 2차원 배열
    vector<vector<int>> snail(n+1,vector<int>(n+1,0));
    // 배열 좌표 진행방향
    int dx[] = {1, 0, -1};
    int dy[] = {0, 1, -1};
    
    int movecount = 0, dir = 0;  // 이동 횟수, 이동방향 인덱스
    int tomove = n;     // 이동해야 할 횟수
    int i = 1, j = 1, value = 1;// x좌표, y좌표, 배열에 들어갈 값
    
    while(tomove > 0)
    {
        // 이차원 배열에 값 입력 후 이동 횟수 증가
        snail[i][j] = value++;
        movecount++;
        
        // 이동해야 할 횟수만큼 이동했으면 방향 전환
        if(movecount == tomove)
        {
            dir = (dir+1) % 3;
            movecount = 0;
            tomove--;
        }
        
        i += dx[dir];
        j += dy[dir];
    }
    
    // 전체 이동 완료시 0 제외한 값 일차원배열에 옮기기
    for (i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if (snail[i][j] != 0)
            {
                answer.push_back(snail[i][j]);
            }
        }
    }
    return answer;
}