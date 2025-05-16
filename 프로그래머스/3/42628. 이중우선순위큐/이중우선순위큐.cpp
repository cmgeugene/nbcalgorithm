#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void processing(multiset<int>& dq, string& operation)
{
    string command = operation.substr(0,1);
    string number = operation.substr(2);
    if(command == "I")
    {
        dq.insert(stoi(number));
    }
    else if(command == "D")
    {
        if(number == "1" && !dq.empty())
        {
            dq.erase(*prev(dq.end()));
        }
        else if(number == "-1" && !dq.empty())
        {
            dq.erase(*dq.begin());
        }
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    // 멀티셋 사용
    multiset<int> dq;
    
    for(string oper : operations)
    {
        processing(dq, oper);
    }
    
    if(dq.empty()) 
        return {0 , 0};
    else
    {
        answer.push_back(*prev(dq.end()));
        answer.push_back(*dq.begin());
    }
    
    return answer;
}