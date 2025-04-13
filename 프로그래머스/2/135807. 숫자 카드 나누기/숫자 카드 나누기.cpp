#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> getDivisors(int g)
{
    vector<int> result;
    
    for(int i = 1; i*i <= g; i++)
    {
        if(g % i == 0) 
        {
            result.push_back(i);
            if(i != g / i) result.push_back(g/i);
        }
    }
    sort(result.rbegin(), result.rend());
    return result;
}

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
    
    vector<int> adivisors = getDivisors(ga);
    vector<int> bdivisors = getDivisors(gb);
    
    for(auto& cd : adivisors)
    {
        if(IsValid(cd, arrayB)) 
        {
            answer = max(cd, answer);
            break;
        }
    }
    for(auto& cd : bdivisors)
    {
        if(IsValid(cd, arrayA))
        {
            answer = max(cd,answer); 
            break;
        }
    }
    
    return answer;
}