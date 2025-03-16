#include <string>
#include <vector>

using namespace std;

int waysOfComposition = 0;

void targetNumber(vector<int>& numbers, int& target, int sum, int index)
{
    if(numbers.size() == index)
    {
        if(sum == target) waysOfComposition++; return;
    }
    
    targetNumber(numbers, target, sum + numbers[index], index +1);
    targetNumber(numbers, target, sum - numbers[index], index +1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    targetNumber(numbers, target, 0, 0);
    return waysOfComposition;
}