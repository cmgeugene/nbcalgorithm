#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";
    temp = s;
    char x;
    int isx = 0, notx = 0;
    // 분리하고 남은 문자열 저장할 변수 temp
    // x횟수, !x횟수 저장할 변수
    // 변수에 다시 해당 작업 수행 -> 반복문 마지막에 변수temp 를 전달하도록
    // 문자열 끝까지 도달하면 break; 따로 필요 없을듯?
    x = temp[0];
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == x) isx++;
        else if(s[i] != x) notx++;
        
        if(isx == notx)
        {
            temp = s.substr(i+1);
            answer++;
            x = temp[0];
            if(i == s.size()-1) return answer;
        }

    }
    return answer + 1;
}