#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    // 집합이 존재하지 않는 경우
    if(s < n) return {-1};
    
    int base = s / n;
    int remainder = s % n;
    
    vector<int> answer(n, base);
    
    for(int i = 0; i < remainder; i++)
    {
        answer[n -1 - i]++;
    }
    
    return answer;
}