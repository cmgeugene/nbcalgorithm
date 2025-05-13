#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long power(int base, int exp) 
{
    long long res = 1;
    for (int i = 0; i < exp; ++i) 
    {
        res *= base;
    }
    return res;
}

long long countOnes(int n, long long start, long long end)
{
    long long total = 0;
    long long blocklength = power(5, n - 1);
    
    if(n == 0)
    {
        return (start <= 0 && 0 <= end) ? 1 : 0;
    }
    
    for(int i = 0; i < 5; i++)
    {
        long long startidx = i * blocklength;
        long long endidx = (i+1) * blocklength -1;
        
        // 범위에 겹치지 않을 때
        if(end < startidx || start > endidx) continue;
        
        // 중간 블럭 
        if(i == 2) continue;
        // 현재 구간이 l r 범위에 포함되는 경우
        else if (start <= startidx && endidx <= end)
        {
            total += power(4, n-1);
        }
        // 일부 겹치는 경우
        else
        {
            long long overlapstart = max(start, startidx);
            long long overlapend = min(end, endidx);
            
            total += countOnes(n - 1, overlapstart - startidx, overlapend - startidx);
        }
    }
    return total;
}

long long solution(int n, long long l, long long r) {
    long long answer = 0;
    //1. 유사 칸토어 비트열은 5등분해서 만든다
    //2. 5개의 블록 중 3번째 블록은 00000, 나머지 블록은 11011이 된다.
    //3. n번째 유사 칸토어 비트열의 길이는 5^n 이다.
    
    answer = countOnes(n, l-1, r-1);
    return answer;
}