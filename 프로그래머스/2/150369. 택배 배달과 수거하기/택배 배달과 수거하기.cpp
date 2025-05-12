#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    // 가장 먼거리부터 처리하는 게 효율적
    // 왕복마다 트럭의 남은 용량 계산
    long long totaldelivery = 0;
    long long totalpickup = 0;
    for(int i = n-1; i >= 0; --i)
    {
        totaldelivery += deliveries[i];
        totalpickup += pickups[i];
        
        while(totaldelivery > 0 || totalpickup > 0)
        {
            // 현재 집까지 왕복 거리 추가
            answer += (long long)2 * (i+1);
            // 배달 처리와 픽업 처리
            totaldelivery -= cap;
            totalpickup -= cap;
            
           
        }
    }
    
    return answer;
}