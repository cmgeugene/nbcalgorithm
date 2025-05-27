#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer;
bool found = false;

void dfs(string current, map<string, vector<pair<string, bool>>>& graph, vector<string>& path, int ticketCount)
{
    // 경로에 현재 도시 추가
    path.push_back(current);
    
    // 종료 조건 : 티켓 모두 사용
    if(path.size() == ticketCount +1)
    {
        answer = path;
        found = true;
        return;
    }
    
    for(auto& ticket : graph[current])
    {
        string& nextcity = ticket.first;
        bool& used = ticket.second;
        
        if(!used)
        {
            used = true;
            dfs(nextcity, graph, path, ticketCount);
            used = false;
            if(found) return;
        }
    }
    // 백트래킹 경로 되돌리기
    path.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    
    
    map<string, vector<pair<string, bool>>> graph;
    
    for(auto& t : tickets)
    {
        // {도착지, 사용여부}
        graph[t[0]].push_back({t[1], false}); 
    }
    
    // 그래프 사전순 정렬
    for(auto& g : graph)
    {
        sort(g.second.begin(), g.second.end());
    }
    // 여행 경로
    vector<string> path;
    dfs("ICN", graph, path, tickets.size());

    return answer;
}