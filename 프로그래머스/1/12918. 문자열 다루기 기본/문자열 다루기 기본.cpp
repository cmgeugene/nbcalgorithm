#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    for(char t : s){
        if((int)t <= 47 || (int)t >= 59)
            return false;
    }
    if(s.size() != 4 && s.size() != 6)
        return false;
    return answer;
}