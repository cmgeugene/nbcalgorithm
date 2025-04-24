#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long count = 0;

    for (long long x = 1; x <= r2; x++) 
    {
        // r2에 대해 가능한 y 최대값
        long long y_max = floor(sqrt((long long)r2 * r2 - x * x));

        // r1에 대해 가능한 y 최소값
        long long y_min = 0;
        if (x < r1) 
            y_min = ceil(sqrt((long long)r1 * r1 - x * x));
        
        // 해당 x에 대해 가능한 y 개수 누적
        count += (y_max - y_min + 1);
    }

    // 대칭이므로 x축 위 아래 모두 포함 → 2배
    return count * 4;
}
