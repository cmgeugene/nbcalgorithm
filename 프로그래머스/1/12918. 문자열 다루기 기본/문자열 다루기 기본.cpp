#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() != 4 && s.size() != 6)
        return false;
    for(char t : s){
        if(!isdigit(t))
            return false;
    }
    return answer;
}