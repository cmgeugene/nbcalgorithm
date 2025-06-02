#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    // 1 -1 1 -1 혹은 -1 1 -1 1 인지 두 가지 케이스
    int n = sequence.size();
    
    long long max1 = sequence[0], max2 = -sequence[0];
    long long current1 = sequence[0], current2 = -sequence[0];
    
    for(int i = 1; i < n; i++)
    {
        // 펄스 수열 -> 펄스 적용
        int sign = (i % 2 == 0) ? 1 : -1;
        long long val1 = sequence[i] * sign;
        long long val2 = sequence[i] * -sign;
        
        current1 = max(val1, current1 + val1);
        current2 = max(val2, current2 + val2);
        
        max1 = max(max1, current1);
        max2 = max(max2, current2);
    }
    
    return max(max1, max2);
}