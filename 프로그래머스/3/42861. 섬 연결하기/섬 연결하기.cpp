#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    // 가중치가 있는 간선
    vector<vector<pair<int, int>>> graph(n);
    for(vector<int> list : costs)
    {
        int a = list[0];
        int b = list[1];
        int cost = list[2];
        
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    
    // 방문배열
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que; // {비용, 섬 번호}
    
    que.push({0, 0});
    int totalcost = 0;
    
    while(!que.empty())
    {
        int cost = que.top().first;
        int node = que.top().second;
        que.pop();
        
        if(visited[node]) continue;
        
        visited[node] = true;
        totalcost += cost;
        
        for(auto& cand : graph[node])
        {
            int nextcost = cand.second;
            int nextnode = cand.first;
            if(!visited[nextnode])
            {
                que.push({nextcost, nextnode});
            }
        }
    }
    return totalcost;
}