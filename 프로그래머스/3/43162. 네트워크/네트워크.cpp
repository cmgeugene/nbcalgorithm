#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& computers, vector<bool>& visited)
{
    if(visited[node] == true) return;
    
    visited[node] = true;
    
    for(int i = 0; i < computers.size(); i++)
    {
        if(i != node && computers[node][i] == 1 && !visited[i])
        {
            dfs(i,computers,visited);
        }
    }

}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            dfs(i, computers, visited);
            answer++;
        }
    }
    
    return answer;
}