#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;
vector<int> info;
vector<vector<int>> tree;

void dfs(int sheep, int wolf, vector<int>& cand)
{
    answer = max(answer, sheep);
    
    for(int i = 0; i < cand.size(); i++)
    {
        int node = cand[i];
        int nextsheep = sheep + (info[node] == 0);
        int nextwolf = wolf + (info[node] == 1);
        
        if(nextsheep <= nextwolf) continue;
        
        vector<int> next = cand;
        next.erase(next.begin() + i);
        for(int child : tree[node])
        {
            next.push_back(child);
        }
        
        dfs(nextsheep, nextwolf, next);
    }

}

int solution(vector<int> _info, vector<vector<int>> edges) {
    info = _info;
    int n = info.size();
    
    answer = 0;
    
    tree.assign(n, {});
    for(auto& edge : edges)
    {
        tree[edge[0]].push_back(edge[1]);
    }
    
    vector<int> start = {0};
    dfs(0, 0, start);
    return answer;
}