#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int round = 0, enemytotal = 0;
    // 무적권을 어디에 사용하는지를 구해야 한다
    // 어떤 경우에 무적권을 사용할 것인가?
    
    // 무적권이 충분한 경우
    if(enemy.size() <= k) return enemy.size();
    
    priority_queue<int> hof;
    for(auto& enemynum : enemy)
    {
        hof.push(enemynum);
        n -= enemynum;
        
        if(n < 0)
        {
            if(k > 0 && !hof.empty())
            {
                k--;
                n += hof.top();
                hof.pop();
            }
            else if(k <= 0) return round;
        }
        round++;
    }
    answer = round;
    return answer;
}