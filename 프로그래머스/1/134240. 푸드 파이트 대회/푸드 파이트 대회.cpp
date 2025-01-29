#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    
    for (int i = 1; i < food.size(); i++)
    {
        if (food[i] / 2 != 0)
        {
            int loop = food[i] / 2;
            for (int j = 1; j <= loop; j++)
            {
                temp.push_back('0'+ i);
            }
        }
    }
    answer = temp;
    answer.push_back('0');
    for (string::reverse_iterator rit = temp.rbegin(); rit != temp.rend(); rit++)
    {
        answer.push_back(*rit);
    }
    return answer;
}