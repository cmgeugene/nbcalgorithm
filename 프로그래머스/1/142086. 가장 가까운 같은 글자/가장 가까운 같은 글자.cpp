#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string temp;
    for(int i = 0; i < s.size(); i++){
        if(i == s.find(s[i])) {
            answer.push_back(-1);
        }
        else if(i > s.find(s[i])){  
            temp = s.substr(0,i);
            answer.push_back(i - temp.find_last_of(s[i]));
            temp.clear();
        }
    }
    return answer;
}