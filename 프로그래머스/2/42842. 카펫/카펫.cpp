#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int totalcells = brown + yellow;   
    for(int height = 3; height <= sqrt(totalcells); height++)
    {
        if(totalcells % height == 0)
        {
            int width = totalcells / height;
            if((width -2) * (height - 2) == yellow)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}