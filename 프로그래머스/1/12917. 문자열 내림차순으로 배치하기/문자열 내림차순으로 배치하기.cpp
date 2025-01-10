#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b){
    return a > b;
}
string solution(string s) {
    string answer = s;
    sort(answer.begin(), answer.end(), compare);
    return answer;
}