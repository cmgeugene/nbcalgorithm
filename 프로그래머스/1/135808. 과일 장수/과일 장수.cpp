#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> temp;
    sort(score.begin(), score.end());
    for(int i : score)
    {
        temp.push_back(score.back());
        score.pop_back();
        if(temp.size() == m)
        {
            answer += *min_element(temp.begin(), temp.end()) * m;
            temp.clear();
        }
    }
    
    return answer;
}