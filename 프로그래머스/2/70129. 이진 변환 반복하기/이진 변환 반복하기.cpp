#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_binary(int toint)
{
    string binary = "";
    while(toint != 0)
    {
        if(toint % 2 == 1) binary.push_back('1');
        else binary.push_back('0');
        toint = toint / 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

vector<int> solution(string s) {
    vector<int> answer;
    int xcount = 0;
    int convertcount = 0;

    while(s != "1")
    {
        xcount += count(s.begin(), s.end(), '0');
        s.erase(remove(s.begin(), s.end(), '0'), s.end());

        s = to_binary(s.length());
        convertcount++;
    }
    answer.push_back(convertcount);
    answer.push_back(xcount);
    return answer;
}