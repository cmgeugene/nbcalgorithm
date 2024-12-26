#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 0;
    int i = 0;
    while (i <= n){
        if(i % 2 == 0)
        sum += i;
        i++;
    }
    return sum;
}