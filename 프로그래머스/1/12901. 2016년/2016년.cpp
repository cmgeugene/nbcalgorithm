#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> Day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> DaysInMonth = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays = 0;
    for(int i = 0; i < a-1; i++)
    {
        totalDays += DaysInMonth[i];
    }
    totalDays = totalDays + b - 1;
    answer = Day[totalDays % 7];
    return answer;
}