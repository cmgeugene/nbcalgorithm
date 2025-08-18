#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int goal = nums.size() / 2;
    
    set<int> filtered;
    for(int& digit : nums)
    {
        filtered.insert(digit);
    }
    
    int filtered_num =  filtered.size();
    if(filtered_num >= goal)
    {
        return goal;
    }
    else
    {
        return filtered_num;
    }
    
    return answer;
}