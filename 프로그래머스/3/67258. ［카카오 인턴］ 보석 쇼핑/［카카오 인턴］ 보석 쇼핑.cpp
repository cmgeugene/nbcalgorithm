#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    // 보석의 종류 수 : std::set에 추가
    set<string> gems_num;
    for(auto& gem : gems)
    {
        gems_num.insert(gem);
    }
    int num = gems_num.size();
    
    // 투포인터 - 포인터간 거리는 최소 num이어야함
    // result {포인터A +1, 포인터B +1}
    
    // 포인터 이동을 어떤 알고리즘으로 할 것인가?
    int start = 0, end = 0;
    int min_length = gems.size() +1;
    
    map<string, int> cart;
    
    for(end = 0; end < gems.size(); end++)
    {
        // 오른쪽 포인터 증가
        cart[gems[end]]++;
        
        // 카트에 모든 보석이 들어있다면
        while(cart.size() == num)
        {
            // 최소 길이 갱신
            if(end - start < min_length)
            {
                min_length = end - start;
                answer = {start +1, end+1};
            }   
            
            // 왼쪽 포인터 증가
            cart[gems[start]]--;
            if(cart[gems[start]] <= 0) 
            {
                cart.erase(gems[start]);
            }
            start++;
        }
    }
    return answer;
}