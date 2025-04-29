#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    // A:65 Z:90 까지 M이면 내림 N이면 올림이 빠름
    
    // 총 문자 변경 횟수
    int letterchange = 0;
    for(char t : name)
    {
        if(t <= 'M')
        {
            letterchange += t - 'A';
        }
        else if(t >= 'N')
        {
            letterchange += 'Z' - t + 1;
        }
    }
    
    // 총 커서 변경 횟수
    int cursorchange = 0;
    int n = name.length();
    int movebase = n - 1;
    
    for(int i = 0; i < name.size(); i++)
    {
        // 다음 위치 포인터
        int nextchar = i + 1;
        while(nextchar < name.size() && name[nextchar] == 'A')
        {
            nextchar++;
        }
        // 오른쪽으로 i만큼 가고 다시 돌아와서 끝까지 가는 경우
        int goAndReturn = 2 * i + (n - nextchar);
        // 끝까지 갔다가 다시 돌아와서 i만큼 가는 경우
        int goToEndThenBack = i + 2 * (n - nextchar);
        // 세 가지 경로 중 최소값을 선택
        movebase = min({movebase, goAndReturn, goToEndThenBack});   
    }
    
    cursorchange = movebase;
    answer = letterchange + cursorchange;
    return answer;
}