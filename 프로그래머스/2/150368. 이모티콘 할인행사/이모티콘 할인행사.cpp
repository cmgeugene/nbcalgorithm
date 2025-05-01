#include <vector>
#include <algorithm>
using namespace std;

// 최적 결과를 저장하는 전역 변수
vector<int> answer = {0, 0};

// 사용할 수 있는 할인율 목록
vector<int> discounts = {10, 20, 30, 40};

void dfs(int idx, vector<int>& emoticons, vector<vector<int>>& users, vector<int>& saleRate) {
    int n = emoticons.size();

    // 모든 이모티콘의 할인율을 설정 완료시 각 사용자의 구매 금액 계산
    if (idx == n) 
    {
        int plusUsers = 0;
        int totalSales = 0;
        
        // 사용자별 순회
        for (auto& user : users) 
        {
            int userDiscount = user[0];
            int userLimit = user[1];
            int sum = 0;
            
            // 구매할 이모티콘인지?
            for (int i = 0; i < n; ++i) 
            {
                if(saleRate[i] >= userDiscount)
                {
                    sum += emoticons[i] * (100 - saleRate[i]) / 100; 
                }
            }
            
            // 플러스 구독할지, 그냥 살지
            if(sum >= userLimit) 
            {
                plusUsers++;
            }
            else
            {
                totalSales += sum;
            }
        }

        // 현재 조합의 결과가 더 좋다면 answer 갱신
        if(plusUsers > answer[0] || (plusUsers == answer[0] && totalSales > answer[1]))
        {
            answer[0] = plusUsers;
            answer[1] = totalSales;
        }
        return;
    }

    
    // 현재 이모티콘(idx)에 대해 가능한 할인율을 설정하고 재귀호출
    for (int rate : discounts) 
    {
        saleRate[idx] = rate;
        dfs(idx+1, emoticons, users, saleRate);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> saleRate(emoticons.size());
    dfs(0, emoticons, users, saleRate);
    
    return answer;
}
