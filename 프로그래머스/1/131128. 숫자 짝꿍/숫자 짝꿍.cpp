#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int x[10] = {0};
    int y[10] = {0};
    
    for(int i = 0; i < X.size(); i++)
    {
        x[X[i] - '0']++;
    }
    for(int i = 0; i < Y.size(); i++)
    {
        y[Y[i] - '0']++;
    }
    
    for(int i = 9; i >= 0; i--)
    {
        int minval = min(x[i], y[i]);
        for(int j = 0; j<minval; j++)
        {
            answer += to_string(i);    
        }
        
    }
    if(answer == "") return "-1";
    else if(answer[0] == '0') return "0";
    else return answer;
}