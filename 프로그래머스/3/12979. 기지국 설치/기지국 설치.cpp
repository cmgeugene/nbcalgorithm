#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int coverage = 2 * w + 1;
    int current_pos = 1; 

    for (int station_loc : stations) {
        // 현재 위치와 기지국 커버리지 빈 공간
        if (current_pos < station_loc - w) 
        {
            int gap_length = (station_loc - w) - current_pos;
            // 필요한 기지국 수 계산
            answer += (gap_length + coverage - 1) / coverage;
        }
        // 다음 시작 위치 업데이트
        current_pos = station_loc + w + 1;
    }

    // 마지막 남은 공간 처리
    if (current_pos <= n) 
    {
        int gap_length = n - current_pos + 1;
        answer += (gap_length + coverage - 1) / coverage;
    }
    
    return answer;
}