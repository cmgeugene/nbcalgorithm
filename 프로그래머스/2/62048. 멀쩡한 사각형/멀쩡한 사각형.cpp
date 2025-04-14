#include <numeric>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long total = (long long)w*h;
    long long damaged = w + h - gcd(w,h);
    
    answer = total - damaged;
    return answer;
}