#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, 4) == "zero") { 
            answer += '0'; 
            i += 3; 
        }
        else if (s.substr(i, 3) == "one") { 
            answer += '1'; 
            i += 2; 
        }
        else if (s.substr(i, 3) == "two") {
            answer += '2';
            i += 2;
        }
        else if (s.substr(i, 5) == "three") {
            answer += '3';
            i += 4;
        }
        else if (s.substr(i, 4) == "four") {
            answer += '4';
            i += 3;
        }
        else if (s.substr(i, 4) == "five") {
            answer += '5';
            i += 3;
        }
        else if (s.substr(i, 3) == "six") {
            answer += '6';
            i += 2;
        }
        else if (s.substr(i, 5) == "seven") {
            answer += '7';
            i += 4;
        }
        else if (s.substr(i, 5) == "eight") {
            answer += '8';
            i += 4;
        }
        else if (s.substr(i, 4) == "nine") {
            answer += '9';
            i += 3;
        }
        else if (isdigit(s[i])) {
            answer += s[i];
        }
    }

    return stoll(answer);
}
