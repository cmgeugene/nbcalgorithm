#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    vector<int> numbers = {};
    
    for(char c : s)
    {
        if(c == ' ')
        {
            numbers.push_back(stoi(temp));
            temp.clear();
        }
        else
        {
            temp += c;
        }
    }
    numbers.push_back(stoi(temp));
    
    sort(numbers.begin(), numbers.end());
    answer = to_string(numbers.front()) + ' ' + to_string(numbers.back()); 
    
    return answer;
}