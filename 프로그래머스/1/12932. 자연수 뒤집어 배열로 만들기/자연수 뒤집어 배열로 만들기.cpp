#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int i = 0;
    while(n != 0){
        i = n % 10;
        answer.push_back(i);
        n = n / 10;
    }
    return answer;
}