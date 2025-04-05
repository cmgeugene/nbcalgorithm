#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    // 시계방향으로 한 칸씩 회전 -> 동일한 크기의 방문배열 필요.. 동일한 크기가 필요한가?
    // 쿼리가 rows * columns 안에서 주어지니까 전체 크기의 방문 배열이 필요할 것 같다.
    // 칸에 도달하면 먼저 현재 값을 큐에 넣고/front()를 현재 좌표에 입력/다음칸 이동
    // 이동시에 최소값 갱신은 큐에 들어온 애들 중 최소값 체크
    // 방문한 곳을 기억해뒀다가 방문배열 초기화.
    queue<int> iter;
    // 행렬 만들기
    vector<vector<int>> matrix(rows, vector<int>(columns));
    int elem = 1;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            matrix[i][j] = elem;
            elem++;
        }
    }
    // 방문 배열 만들기 필요 없음
    //vector<vector<bool>> visited(rows, vector<bool>(columns, false));
    
    // 테두리 순회 시작
    for(auto& query : queries)
    {
        int min = 10000;
        int begin_x = query[0]-1, begin_y = query[1]-1;
        int end_x = query[2]-1, end_y = query[3]-1;
        
        iter.push(matrix[begin_x][begin_y]);
        for(int i = begin_y +1 ; i <= end_y; i++)
        {
            if(!iter.empty() && iter.front() <= min) min = iter.front();
            
            iter.push(matrix[begin_x][i]);         
            matrix[begin_x][i] = iter.front();
            iter.pop();
        }
        for(int j = begin_x+1; j <= end_x; j++)
        {
            if(!iter.empty() && iter.front() <= min) min = iter.front();
            
            iter.push(matrix[j][end_y]);         
            matrix[j][end_y] = iter.front();
            iter.pop();
        }
        for(int k = end_y-1; k >= begin_y; k--)
        {
            if(!iter.empty() && iter.front() <= min) min = iter.front();
            
            iter.push(matrix[end_x][k]);         
            matrix[end_x][k] = iter.front();
            iter.pop();
        }
        for(int l = end_x-1; l >= begin_x; l--)
        {
            if(!iter.empty() && iter.front() <= min) min = iter.front();
            
            iter.push(matrix[l][begin_y]);         
            matrix[l][begin_y] = iter.front();
            iter.pop();
        }
        answer.push_back(min);
        
        while(!iter.empty())
        {
            iter.pop();    
        }
    }
    return answer;
}