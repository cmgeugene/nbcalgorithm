#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int count = 0;
    long long temp = (long long)num;
    if(temp == 1)
        answer = 0;
    else {
        while(temp != 1) {
            if(temp % 2 == 0){
                temp = temp / 2;
                count++;
            }
            else {
                temp = temp * 3 + 1;
                count++;
            }
        }
    }
    if(count < 500)
        answer = count;
    else answer = -1;
    return answer;
}
