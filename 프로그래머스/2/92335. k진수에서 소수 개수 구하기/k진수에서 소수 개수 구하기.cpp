#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string convert(int n, int k)
{
    string temp = "";
    while(n != 0)
    {
        temp += to_string(n % k);
        n /= k;
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

bool isPrime(long long n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    for(long long i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string converted = convert(n, k);
    string buffer = "";
    
    for(char c : converted)
    {
        if(c == '0')
        {
            if(!buffer.empty() && isPrime(stoll(buffer)))
            {
                answer++;
            }
            buffer.clear();
        }
        else
        {
            buffer += c;
        }
    }
    
    if(!buffer.empty() && isPrime(stoll(buffer)))
    {
        answer++;
    }
    return answer;
}