#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<int> ways(n+1,0);
    ways[1] = 1;
    ways[2] = 2;
    for(int i = 3; i < ways.size(); i++)
    {
        ways[i] = (ways[i-1] + ways[i-2]) % 1234567;
    }
    answer = ways[n];
    return answer;
}