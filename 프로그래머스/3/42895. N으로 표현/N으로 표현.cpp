#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int>> dp(9); // 8 이상은 -1이므로
    
    
    for(int k = 1; k <= 8; k++)
    {
        // N이 이어진 값 추가
        int concat = 0;
        for(int i = 0; i < k; i++)
        {
            concat = concat * 10 + N;
        }
        dp[k].insert(concat);
        
        for (int i = 1; i < k; ++i) 
        {
            for (int x : dp[i])            // 왼쪽 후보 값
            {                               
                for (int y : dp[k - i])    // 오른쪽 후보 값
                {  
                    dp[k].insert(x + y);   // 덧셈
                    dp[k].insert(x - y);   // 뺄셈
                    dp[k].insert(x * y);   // 곱셈
                    if (y != 0) dp[k].insert(x / y); // 정수 나눗셈
                }
            }
        }
        if(dp[k].count(number)) return k;
    }
    
    
    return answer;
}