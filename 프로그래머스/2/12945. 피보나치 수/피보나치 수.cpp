#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num(n+1, 0);
    num[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        num[i] = (num[i-1] + num[i-2]) % 1234567;
    }
    answer = num[n];
    return answer;
}