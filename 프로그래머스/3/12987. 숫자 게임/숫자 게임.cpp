#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int score = 0;
    
    // A[i]보다 큰 수 중 가장 작은 수를 내야 최대 승점
    
    // A와 B를 모두 오름차순으로 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int a_idx = 0; // A의 현재 카드 인덱스
    
    // B의 모든 카드 순회
    for (int b_idx = 0; b_idx < B.size(); b_idx++) 
    {
        // B의 카드가 A의 카드보다 크다면
        if (B[b_idx] > A[a_idx]) 
        {
            score++;    // 승점 획득
            a_idx++;    // 다음 A 카드 설정
        }
        // B가 이길 수 없다면 넘어감
    }
    
    return score;
}