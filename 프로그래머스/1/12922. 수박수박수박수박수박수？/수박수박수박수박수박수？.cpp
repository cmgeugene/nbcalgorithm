#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i = 1; i <= n ; i++){
        i % 2 == 0 ? answer = answer + "박" : answer = answer + "수";
    }
    return answer;
}