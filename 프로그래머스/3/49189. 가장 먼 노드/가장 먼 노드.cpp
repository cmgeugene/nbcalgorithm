#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // edge 그래프로 그리기
    vector<vector<int>> graph(n+1);
    for(auto& list : edge)
    {
        int a = list[0];
        int b = list[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    // 최단 경로, 간선 개수 = 중복방문x, bfs, depth
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> que; // 노드번호, 뎁스
    int maxdepth = 0, maxdepthcount = 0;
    
    que.push({1, 0});
    visited[1] = true;
    
    while(!que.empty())
    {
        int current = que.front().first;
        int depth = que.front().second;
        que.pop();
        
        if(depth > maxdepth)
        {
            maxdepth = depth;
            maxdepthcount = 1;
        }
        else if(depth == maxdepth)
        {
            maxdepthcount++;
        }
        
        for(int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if(!visited[next])
            {
                que.push({next, depth + 1});
                visited[next] = true;
            }
        }
    }

    return maxdepthcount;
}