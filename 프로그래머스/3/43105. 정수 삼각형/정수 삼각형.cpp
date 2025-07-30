#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // vector<vector<int>> 선언
    // depth의 위치마다 가능한 가장 큰 수 계산
    // 배열의 back() 에서 가장 큰 원소 반환
    
    vector<vector<int>> dp;
    
    // 초기화
    for(auto& row : triangle)
    {
        dp.push_back(vector<int>(row.size(), 0));
    }
    dp[0][0] = triangle[0][0];
    
    // 계산
    for(int i = 1; i < dp.size(); i++)
    {
        int width = triangle[i].size();
        for(int j = 0; j < width; j++)
        {
            // 엣지 케이스 먼저 처리
            if(j == 0)
            {
                dp[i][j] = triangle[i][j] + dp[i-1].front();    
            }
            else if(j == width -1)
            {
                dp[i][j] = triangle[i][j] + dp[i-1].back();
            }
            else
            {
                // 대각선 위 중 큰 값 더하기
                int formervalue = 
                    dp[i-1][j-1] >= dp[i-1][j] ? dp[i-1][j-1] : dp[i-1][j];
                dp[i][j] = triangle[i][j] + formervalue;
            }
            
        }
    }
    
    answer = *max_element(dp.back().begin(), dp.back().end());
    
    return answer;
}