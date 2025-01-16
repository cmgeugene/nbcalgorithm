#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int j = 0;
    vector<int> r_ternary;
    while(n != 0){
        r_ternary.push_back(n % 3);
        n = n/3;
    }
    for(int i = r_ternary.size() - 1; i >= 0; i--){
        answer += r_ternary[i] * pow(3,j);
        j++;
    }
    
    return answer;
}