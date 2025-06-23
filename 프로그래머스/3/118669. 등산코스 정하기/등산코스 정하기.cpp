#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>

using namespace std;

const int INF = INT_MAX;

bool compare(vector<int>& a, vector<int>& b)
{
    if(a[1] == b[1]) return a[0]<b[0];
    return a[1] < b[1];
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<vector<int>> answer_cand;
    
    // 그래프 그리기
    vector<vector<pair<int, int>>> pathmap(n+1);
    for(auto& path : paths)
    {
        pathmap[path[0]].push_back({path[1], path[2]});
        pathmap[path[1]].push_back({path[0], path[2]});
    }
    
    // 게이트 확인용 셋
    set<int> summitSet(summits.begin(), summits.end());
    
    // 게이트에서 출발
    vector<int> dist(n+1, INF);
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pque;
    
    for(int gate : gates)
    {
        dist[gate] = 0;
        pque.push({0, gate});
        
    }
    
    while (!pque.empty()) 
    {
        P curr = pque.top();
        int intensity = curr.first;
        int current = curr.second;
        pque.pop();
        
        if (intensity > dist[current]) continue;           
        if (summitSet.count(current)) continue;        
    
        for (auto& path : pathmap[current]) 
        {
            int next = path.first;
            int weight = path.second;
            int nextInten = max(intensity, weight);         
            if (nextInten < dist[next]) 
            {
                dist[next] = nextInten;
                pque.push({nextInten, next});
            }
        }
    }
    
    sort(summits.begin(), summits.end());        
    int bestSummit = -1, bestInten = INF;
    for (int s : summits) {
        if (dist[s] < bestInten) {                
            bestInten = dist[s];
            bestSummit = s;
        }
    }
    return {bestSummit, bestInten};
}