#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> divisors(number + 1, 0);
    for(int i = 1; i <= number; i++)
    {
        for(int j = i; j <= number; j += i)
            divisors[j]++;
    }
        
    for(int i = 1; i <= number; i++)
    {
        if(divisors[i] > limit) answer += power;
        else if(divisors[i] <= limit) answer += divisors[i];
    }
    return answer;
}