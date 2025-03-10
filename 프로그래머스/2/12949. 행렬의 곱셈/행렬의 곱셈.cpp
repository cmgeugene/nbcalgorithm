#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size())); // 정답의 크기 초기화
    
    for(int i = 0; i < arr1.size(); i++) { // 행 순회
        for(int j = 0; j < arr2[0].size(); j++) { // 열 순회
            int inner = 0;
            for(int k = 0; k < arr1[0].size(); k++) { // 곱셈 연산
                inner += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = inner; // 결과 저장
        }
    }
    
    return answer;
}
