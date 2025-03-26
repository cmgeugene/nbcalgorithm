#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    // 비교 문자열 길이가 같을 경우
    if(a.size() == b.size())
    {
        if(a.size() > 1 && a[0] == b[0]) 
        {
            if(a.size() > 2 && a[1] == b[1])
            {
                return a[2] > b[2];
            }
            return a[1] > b[1]; 
        }
        return a > b;
    }
    // 자리수가 다를 경우
    else if(a.size() != b.size())
    {
        int ab = stoi(a + b);
        int ba = stoi(b + a);
        if(ab > ba) return ab > ba;
        else if(ba > ab) return ab > ba;
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    // 자리수 기준 정렬 같으면 두번째 자리, 세번째 자리
    vector<string> string_numbers;
    for(int num : numbers)
    {
        string_numbers.push_back(to_string(num));
    }
    
    sort(string_numbers.begin(), string_numbers.end(), compare);
    
    for(string num : string_numbers)
    {
        answer += num;
    }
    
    // numbers의 모든 원소가 0일 경우
    int countifzero = count(string_numbers.begin(), string_numbers.end(), "0");
    if(countifzero == string_numbers.size())
    {
        answer = "0";
    }
    
    return answer;
}