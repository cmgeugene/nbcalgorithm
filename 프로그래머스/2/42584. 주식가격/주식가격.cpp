#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    stack<int> prices_index;
    prices_index.push(0);
    for(int i = 1; i < prices.size(); i++)
    {
        // 가격이 떨어짐
        while(!prices_index.empty() && prices[prices_index.top()] > prices[i])
        {
            int top_idx = prices_index.top();
            prices_index.pop();
            
            answer[top_idx] = i - top_idx;
        }
        prices_index.push(i);
    }
    
    int lastindex = prices.size() - 1;
    while(!prices_index.empty())
    {
        answer[prices_index.top()] = lastindex - prices_index.top();
        prices_index.pop();
    }
    return answer;
}