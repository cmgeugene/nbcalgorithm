#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    // 5개 단위 그룹으로 나누기
    vector<vector<string>> groups;
    vector<string> temp;
    for (int i = 0; i < minerals.size(); i++) 
    {
        temp.push_back(minerals[i]);
        if (temp.size() == 5) 
        {
            groups.push_back(temp);
            temp.clear();
        }
    }
    // 마지막에 5개 미만 블록 처리
    if (!temp.empty()) 
    {  
        groups.push_back(temp);
    }
    
    // 곡괭이 수 세기
    vector<string> pickaxes;
    for (int i = 0; i < picks.size(); i++) 
    {
        for (int j = 0; j < picks[i]; j++) 
        {
            if (i == 0) pickaxes.push_back("diamond");
            else if (i == 1) pickaxes.push_back("iron");
            else if (i == 2) pickaxes.push_back("stone");
        }
    }
    int num_picks = pickaxes.size();
    
    // 그룹별 피로도 계산
    vector<pair<int, vector<string>>> cost_groups;
    for(auto& group : groups)
    {
        int cost = 0;
        for(auto& mineral : group)
        {
            if(mineral == "diamond") cost += 25;
            else if(mineral == "iron") cost += 5;
            else if(mineral == "stone") cost += 1;
        }
        cost_groups.push_back({cost, group});
    }
    int num_groups = cost_groups.size();
    
    // 곡괭이의 수와 블록의 수 비교해서 정렬
    if(num_picks >= num_groups)
    {
        sort(cost_groups.begin(), cost_groups.end(), greater<>());    
    }
    else if(num_picks < num_groups)
    {
        sort(cost_groups.begin(), cost_groups.begin() + num_picks, greater<>());
    }
    
    // 피로도 많이 필요한 그룹, 좋은 곡괭이 순으로 순회->피로도 더하기
    int idx_pickaxe = 0;
    for(auto& cost_group : cost_groups)
    {
        if(idx_pickaxe >= pickaxes.size()) break;
        
        string pickaxe = pickaxes[idx_pickaxe];
        
        for(auto& mineral : cost_group.second)
        {
            if(pickaxe == "diamond") answer += 1;
            
            else if(pickaxe == "iron")
            {
                if(mineral == "diamond") answer += 5;
                else answer += 1;
            }
            else if(pickaxe == "stone")
            {
                if(mineral == "diamond") answer += 25;
                else if(mineral == "iron") answer += 5;
                else answer += 1;
            }
        }
        idx_pickaxe++;
    }
    return answer;
}