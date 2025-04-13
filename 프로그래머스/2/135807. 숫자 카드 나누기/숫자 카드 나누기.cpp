#include <string>
#include <vector>
#include <numeric>
#include <deque>
#include <algorithm>

using namespace std;

bool IsValid(int x, vector<int>& array)
{
    for(int num : array)
    {
        if(num % x == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    // 배열에서 최대공약수 뽑기
    int ga = arrayA[0], gb = arrayB[0];
    for(int a : arrayA)
    {
        ga = gcd(ga, a);
    }
    for(int b : arrayB)
    {
        gb = gcd(gb, b);
    }
    
    if(IsValid(ga,arrayB)) answer = max(answer, ga);
    if(IsValid(gb,arrayA)) answer = max(answer, gb);
    
    return answer;
}