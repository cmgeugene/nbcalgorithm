#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxgap = 0;
vector<int> bestshot;

void updateResult(vector<int>& lion, vector<int>& apeach)
{
    int lionScore = 0, apeachScore = 0;
    for(int i = 0; i < lion.size(); i++)
    {
        if(lion[i] == 0 && apeach[i] == 0) continue;
        if(lion[i] > apeach[i])
        {
            lionScore += 10 - i;
        }
        else apeachScore += 10 - i;
    }
    
    if(lionScore <= apeachScore) return;
    int gap = lionScore - apeachScore;
    
    // 좋은 성적이면 갱신
    if(maxgap < gap)
    {
        maxgap = gap;
        bestshot = lion;
    }
    else if(maxgap == gap)
    {
        for(int i = 10; i >= 0; i--)
        {
            if(lion[i] > bestshot[i])
            {
                bestshot = lion;
                break;
            }
            else if(lion[i] < bestshot[i]) break;
        }
    }
}

void dfs(int idx, int leftchance, vector<int>& info, vector<int>& lion)
{
    if(idx == 11)
    {
        if(leftchance > 0)
        {
            lion[10] += leftchance;
        }
        
        updateResult(lion, info);
        
        if(leftchance > 0)
        {
            lion[10] -= leftchance;
        }
        return;
    }
    
    int need = info[idx] + 1;
    
    if(leftchance >= need)
    {
        lion[idx] = need;
        dfs(idx+1, leftchance - need, info, lion);
        lion[idx] = 0;
    }
    
    dfs(idx+1, leftchance, info, lion);
}
vector<int> solution(int n, vector<int> info) {
    vector<int> lion(11, 0);
    dfs(0, n, info, lion);
    
    if(bestshot.empty()) return {-1};
    return bestshot;
}