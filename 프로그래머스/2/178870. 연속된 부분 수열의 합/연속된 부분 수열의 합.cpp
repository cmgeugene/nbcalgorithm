#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, vector<int>>& a, pair<int, vector<int>>& b)
{
    if(a.first == b.first)
    {
        return a.second[0] < b.second[0]; 
    }
    return a.first < b.first;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int L = 0, R = 0;
    int sum = 0;
    int distanceLR = 0;
    pair<int, vector<int>> dist;
    vector<pair<int, vector<int>>> startend;
    
    while(R < sequence.size())
    {
        sum += sequence[R];
        
        while(sum > k && L <= R)
        {
            sum -= sequence[L];
            L++;
        }
        if(sum == k)
        {
            startend.push_back(make_pair(R-L + 1, vector<int>{L,R}));
        }
        
        R++;
        distanceLR++;
    }
    
    sort(startend.begin(), startend.end(), compare);
    answer.push_back(startend[0].second[0]);
    answer.push_back(startend[0].second[1]);
    return answer;
}