#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> buffer;
    for(int i = 0; i < numbers.size(); i++)
    {
        while(!buffer.empty() && numbers[i] > numbers[buffer.top()])
        {
            answer[buffer.top()] = numbers[i];
            buffer.pop();
        }
        buffer.push(i);
    }
    return answer;
}