#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // 장바구니 맵에 담기
    unordered_map<string, int> wantMap;
    for(int i = 0; i < want.size(); i++)
    {
        wantMap.insert({want[i], number[i]});
    }
    
    // 10일간 할인 목록 맵에 담기
    for(int j = 0; j <= discount.size() - 10; j++)
    {
        unordered_map<string, int> discountMap;
        for(int k = j; k < j + 10; k++)
        {
            discountMap[discount[k]] += 1;
        }
        
        if(wantMap == discountMap)
        {
            answer++;
        }
    }
    
    return answer;
}