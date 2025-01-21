#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(int one = 0; one < number.size() - 2; one++) {
        for(int two = one + 1; two < number.size()-1; two++){
            for(int three = two + 1; three < number.size(); three++){
                if(number[one]+number[two]+number[three] == 0){
                    answer++;
                }
            }
        }
    }
    return answer;
}