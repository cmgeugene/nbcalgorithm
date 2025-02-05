#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int painted = 0;
    for(int num : section)
    {
        if(painted < num)
        {
        painted = num + m-1;
        answer++;
        }
    }
    return answer;
}