#include <string>
#include <vector>
#include <cmath>

using namespace std;

void dfs(int u, vector<vector<int>>& graph, vector<long long>& long_a, vector<bool>& visited, long long& answer)
{
    // 부모 u에 자식 v의 가중치를 더함
    visited[u] = true;
    for(int v : graph[u])
    {
        if(!visited[v])
        {
            dfs(v, graph, long_a, visited, answer);
            answer += abs(long_a[v]);
            long_a[u] += long_a[v];
            long_a[v] = 0;
        }
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    
    int n = a.size();
    long long totalbalance = 0;
    for(auto& v : a)
    {
        totalbalance += v;
    }
    if(totalbalance != 0) return -1;
    
    // a 형변환
    vector<long long> long_a(a.begin(), a.end());
    
    vector<vector<int>> graph(n);
    for(auto& edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n,false);
    dfs(0, graph, long_a, visited, answer);
    
    return answer;
}