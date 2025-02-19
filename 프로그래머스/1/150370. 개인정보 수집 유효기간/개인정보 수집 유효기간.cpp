#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    for (int i = 0; i < terms.size(); i++)
    {
        for (int j = 0; j < privacies.size(); j++)
        {
            // 동일한 약관 종류 검색
            if (privacies[j].find(terms[i][0]) != string::npos)
            {
                string date = privacies[j].substr(0, 10);
                // 만료 일자 정하기
                int termmonth = stoi(terms[i].substr(2));
                int year = stoi(date.substr(0, 4));
                int month = stoi(date.substr(5, 2));
                int day = stoi(date.substr(8, 2));

                if (day == 1)
                {
                   day = 28;
                   month -= 1;
                }
                else day -= 1;
                month += termmonth;
        
                year += (month - 1) / 12;
                month = (month - 1) % 12 + 1;

                string expdate = to_string(year) + '.' + (month < 10 ? "0" : "") + to_string(month) + '.' + (day < 10 ? "0" : "") + to_string(day);

                if (today > expdate)
                {
                    answer.push_back(j + 1);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}