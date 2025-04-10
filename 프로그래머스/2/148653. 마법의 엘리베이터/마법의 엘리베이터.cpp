#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0)
    {
        // 현재 수
        int digit = storey % 10;
        storey /= 10;
        // 다음 수
        int next = storey % 10;
        
        if(digit < 5)
        {
            answer += digit;
        }
        else if(digit > 5)
        {
            answer += (10 - digit);
            storey++;
        }
        else
        {
            if(next >= 5)
            {
                answer += 5; 
                storey++;
            }
            else if(next < 5)
            {
                answer += 5;
            }
        }
    }
    
    return answer;
}