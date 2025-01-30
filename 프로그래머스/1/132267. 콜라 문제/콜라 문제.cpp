#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int currentcoke = n;
    int refundcoke;
    for (int i = currentcoke; i >= a; i--)
    {
        if (i % a == 0)
        {
            refundcoke = (i / a) * b;
            answer = answer + refundcoke;
            currentcoke = (currentcoke - i) + refundcoke;
            i = currentcoke;
            if(i % a == 0) { i++; }
        }
    }
    return answer;
}