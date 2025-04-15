#include <string>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> weightcounts;
    vector<vector<int>> ratios = {{1,1},{2,3},{2,4},{3,2},{3,4},{4,2},{4,3}};
    
    for(int weight : weights)
    {
        for(auto& rat : ratios)
        {
            int target = (long long)weight* rat[0] / rat[1];
            if((long long)weight*rat[0] % rat[1] == 0)
            {
                answer += weightcounts[target];
            }
        }
        weightcounts[weight]++;
    }
    return answer;
}