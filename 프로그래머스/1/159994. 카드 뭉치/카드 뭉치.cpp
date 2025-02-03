#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int order1 = 0;
    int order2 = 0;
    for(int i = 0; i < goal.size(); i++)
    {
        if(cards1[order1] == goal[i]) 
        { 
            order1++; 
        }
        else if (cards2[order2] == goal[i]) 
        { 
            order2++; 
        }
        else return answer = "No";
    }
    answer = "Yes";
    return answer;
}