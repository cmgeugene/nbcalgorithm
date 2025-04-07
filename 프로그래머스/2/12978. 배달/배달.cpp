#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<pair<int, int>>>& graph, int start, int arrive, int time)
{
    graph[start].push_back({arrive, time});
    graph[arrive].push_back({start, time});
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 1;
    // 가중치가 있는 간선 리스트
    // 중복 순회 방지 방문, 누적시간배열
    vector<int> visited(N+1, 0);
    // 그래프 모델링
    vector<vector<pair<int, int>>> graph(N+1);
    for(auto& info : road)
    {
        int start = info[0], arrive = info[1], time = info[2];
        addEdge(graph, start, arrive, time);
    }
    // 큐에 1번 마을 추가
    queue<pair<int, int>> q;
    q.push({1, 0});
    // 마을 순회(큐)
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        if((visited[current.first] != 0 && visited[current.first] < current.second) || current.second > K)
        {
            continue;
        }
        visited[current.first] = current.second;
        for(auto& next : graph[current.first])
        {
            if(next.first != 1)
            {
                q.push({next.first, current.second + next.second});
            }
        }
    }
    for(auto& v : visited)
    {
        if(v) answer++;
    }
    return answer;
}