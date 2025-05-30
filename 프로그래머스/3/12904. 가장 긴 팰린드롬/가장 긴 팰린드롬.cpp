#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int solution(string s)
{
    int answer = 1;
    
    int length = s.size();
    int maxlength = 0;
    
    // 홀수 길이일 때
    for(int i = 0; i < length; i++)
    {
        int left = i - 1;
        int right = i + 1;
        int palindr_length = 1;
        
        while(left >= 0 && right <= length && s[left] == s[right])
        {
            palindr_length += 2;
            left--;
            right++;
        }
        
    answer = max(answer, palindr_length);
    
    // 짝수 -> 변수 초기화
    left = i;
    right = i + 1;
    palindr_length = 0;
    
        while(left >= 0 && right <= length && s[left] == s[right])
        {
            palindr_length += 2;
            left--;
            right++;
        }
    answer = max(answer, palindr_length);
    
    }
    
    return answer;
}