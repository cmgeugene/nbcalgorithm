#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 홀수면 가득 채우기 불가
    if(n % 2 != 0) return 0;
    
    // 짝수면 DP 테이블에 경우의 수 저장
    vector<long long> dp(n+1, 0);
    long long MOD = 1000000007;
    
    dp[0] = 1;
    if(n >= 2)
    {
        dp[2] = 3;
    }
    
    for(int i = 4; i <= n; i += 2)
    {
        dp[i] = (dp[i - 2] * 3);
        
        // 특수 케이스
        for(int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] = (dp[i] + dp[j] * 2);
        }
        
        dp[i] %= MOD;
    }
    
    return dp[n];
}