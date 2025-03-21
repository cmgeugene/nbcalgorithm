#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    // 토핑 종류별 개수
    map<int, int> part1, part2;
 
    for(int i = 0; i < topping.size(); i++)
    {
        part2[topping[i]]++;
    }
    
    for(int j = 0; j < topping.size(); j++)
    {
        part2[topping[j]]--;
        if(part2[topping[j]] == 0)
        {
            part2.erase(topping[j]);
        }
        part1[topping[j]]++;
        
        if(part1.size() == part2.size()) answer++;
    }
    return answer;
}