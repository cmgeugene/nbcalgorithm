#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    int MAX = max(a,b);
    int MIN = min(a,b);
    
    while(MAX % MIN != 0)
    {
        int R = MAX % MIN;
        MAX = MIN;
        MIN = R;
    }
    return MIN;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++)
    {
        int count = gcd(answer, arr[i]);
        int cm = answer * arr[i] / count;
        answer = cm;
    }
    return answer;
}