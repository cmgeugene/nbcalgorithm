#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> target) {
    vector<int> answer(target.size(), 0); 
    int min_press;
    for(int i = 0; i <target.size() ; i++)
    {
        int presscount = 0;
        for(int j = 0; j < target[i].size(); j++)
        {
            min_press = 999999;
            char t = target[i][j];
            for(int k = 0; k < keymap.size(); k++)
            {
                if(keymap[k].find(t) != string::npos)
                {
                    min_press = min(min_press, (int)keymap[k].find(t) + 1);
                }
            }
            if(min_press == 999999)
            {
                presscount = -1;
                break;
            }
            else presscount += min_press;
        }
        answer[i] = presscount;
    }

    return answer;
}