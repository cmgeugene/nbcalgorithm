#include <string>
#include <vector>

using namespace std;

void DFS(int x, int y, vector<int>& answer, vector<vector<int>>& arr, int size)
{
    int sum = 0;
    // 현재 영역 순회
    for(int i = x; i < x + size; i++)
    {
        for(int j = y ; j < y + size; j++)
        {
            sum += arr[i][j];
        }
    }
    //0 혹은 1로만 이루어져있다면 정답 배열에 추가하고 종료
    if(sum == 0)
    {
        answer[0]++;
        return;
    }
    else if(sum == size * size)
    {
        answer[1]++;
        return;
    }
    
    // 그렇지 않다면 현재 영역을 4개의 영역으로 나누기
    DFS(x, y, answer, arr, size/2); // 2사분면
    DFS(x + size/2, y, answer, arr, size/2); // 1사분면
    DFS(x, y + size/2, answer, arr, size/2); // 3사분면
    DFS(x + size/2, y + size/2, answer, arr, size/2); // 4사분면
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    int size = arr.size();
    DFS(0, 0, answer, arr, size);
    return answer;
}