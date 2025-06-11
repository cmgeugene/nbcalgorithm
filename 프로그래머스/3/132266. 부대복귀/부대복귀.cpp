#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    // 그래프 그리기
    vector<vector<int>> graph(n+1);
    for(vector<int> road : roads)
    {
        int a = road[0], b = road[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    // 그래프로 bfs 돌기
    vector<int> dist(n+1, -1);
    queue<int> que; 
    dist[destination] = 0;
            
    que.push(destination);
        
    while(!que.empty())
    {
        int current = que.front();
        que.pop();

        for(int next : graph[current])
        {
            if(dist[next] == -1)
            {
                dist[next] = dist[current] + 1;
                que.push(next);
            }
        }
        
    }
    
    for(int agent : sources) answer.push_back(dist[agent]);
    
    return answer;
}