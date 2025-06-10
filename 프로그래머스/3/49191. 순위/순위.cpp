#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int calculateWins(int& n, int index, map<int, vector<int>>& graph_win)
{
    int wins = 0;
    vector<bool> visited(n+1, false);
    queue<int> que;
    
    // 간접적으로 이긴 선수 탐색
    visited[index] = true;
    que.push(index);
    
    while(!que.empty())
    {
        int current = que.front();
        que.pop();
        
        for(auto& t : graph_win[current])
        {
            if(!visited[t])
            {
                visited[t] = true;
                wins++;
                que.push(t);
            }
        }
    }
    return wins;
}

int calculateLose(int& n, int index, map<int, vector<int>>& graph_lose)
{
    int lose = 0;
    vector<bool> visited(n+1, false);
    queue<int> que;
    
    // 간접적으로 날 이긴 선수 탐색
    visited[index] = true;
    que.push(index);
    
    while(!que.empty())
    {
        int current = que.front();
        que.pop();
        
        for(auto& t : graph_lose[current])
        {
            if(!visited[t])
            {
                visited[t] = true;
                lose++;
                que.push(t);
            }
        }
    }
    return lose;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    // [a, b] == b가 a보다 등수가 낮다
    map<int, vector<int>> graph_lose; // key를 이긴 선수
    map<int, vector<int>> graph_win; // key가 이긴 선수
    for(auto& result : results)
    {
        graph_lose[result[1]].push_back(result[0]);
        graph_win[result[0]].push_back(result[1]);
    }
    
    for(int i = 1; i <= n; i++)
    {
        int winfrom = calculateWins(n, i, graph_win);
        int losefrom = calculateLose(n, i, graph_lose);
        
        if(winfrom + losefrom == n-1) answer++;
    }
    return answer;
}