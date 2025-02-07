#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int hit = 0, redacted = 0;
    for(int num : win_nums)
    {
        vector<int>::iterator it = find(lottos.begin(), lottos.end(), num);
            if(it != lottos.end()) hit++;
    }
    for(int num : lottos)
    {
        if(num == 0) redacted++;
    }
    int max_hit = hit + redacted;
    int min_hit = hit;
    if(min_hit < 2) min_hit = 1;
    if(max_hit == 0) max_hit = 1;
    answer.push_back(7 - max_hit);
    answer.push_back(7 - min_hit);
    return answer;
}