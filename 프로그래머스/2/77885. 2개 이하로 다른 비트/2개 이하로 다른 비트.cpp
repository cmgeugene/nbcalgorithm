#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long number : numbers)
    {
        // 짝수일 경우 +1
        if(number % 2 == 0)
        {
            answer.push_back(number + 1);
        }
        // 홀수일 경우 최하위 0의 자리를 구한 후 
        // 그 앞자리에 1비트를 더해준다
        else
        {
            long long bit = 1;
            while(1)
            {
                if(!(number & bit)) break;
                bit <<= 1;
            }
            bit >>= 1;
            
            answer.push_back(number + bit);
        }
        
    }
    return answer;
}