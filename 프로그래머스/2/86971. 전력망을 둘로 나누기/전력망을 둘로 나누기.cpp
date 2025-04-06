#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void addEdge(vector<vector<int>>& graph, int a, int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void removeEdge(vector<vector<int>>& graph, int a, int b)
{
    graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
    graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());
}

int DFS(int node, vector<vector<int>>& graph, vector<bool>& visited)
{
    visited[node] = true;
    int nodecount = 1;
    
    for(int neighbor : graph[node])
    {
        if(!visited[neighbor])
        {
            nodecount += DFS(neighbor, graph, visited);
        }
    }
    
    return nodecount;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    int nodecount = 1;
    
    vector<vector<int>> graph(n+1);
    
    // 인접 리스트 생성
    for(auto& wire : wires)
    {
        addEdge(graph, wire[0], wire[1]);
    }
    
    for(auto& wire : wires)
    {
        int a = wire[0], b = wire[1];
        
        removeEdge(graph, a, b);
        
        vector<bool> visited(n+1, false);
        int componentSize = DFS(a, graph, visited);
        
        addEdge(graph,a,b);
        
        answer = min(answer,abs(n - 2 * componentSize));
    }
    
    return answer;
}