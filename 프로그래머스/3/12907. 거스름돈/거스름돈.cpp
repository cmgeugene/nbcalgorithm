#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < money.size(); i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(money[i] <= j)
            {
                dp[j] = (dp[j] + dp[j - money[i]]) % 1000000007;
            }
        }
    }
    return dp.back();
}