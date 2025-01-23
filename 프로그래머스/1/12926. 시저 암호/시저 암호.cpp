#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    for(int i = 0; i < s.size(); i++){
        if(answer[i] == ' ') { }
        else if(answer[i] >= 65 && answer[i] <= 90) {
            if(answer[i] + n > 90) {
                answer[i] = (answer[i] + n) - 26;
            } else {
                answer[i] += n;
            }
        }
        else if(answer[i] >= 97) {
            if(answer[i] + n > 122){
                answer[i] = (answer[i] + n) - 26;
            } else {
                answer[i] += n;
            }
        }
    }
    return answer;
}
