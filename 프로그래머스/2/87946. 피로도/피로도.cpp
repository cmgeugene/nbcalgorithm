#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxVisitCount = 0;

void exploreDungeons(int k, vector<vector<int>>& dungeons, int visitCount)
{
    int fatigue = k;
    // 최대 탐험 횟수 갱신
    maxVisitCount = max(maxVisitCount, visitCount);
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        // 현재 피로도 >= 최소 요구 피로도 && 방문하지 않은 곳이면
        if(dungeons[i][0] <= fatigue && dungeons[i][1] != -1)
        {
            //백트래킹을 위한 백업
            int fatigue_backup = dungeons[i][1];
            //방문 표시
            dungeons[i][1] = -1;
            exploreDungeons(fatigue - fatigue_backup, dungeons, visitCount + 1);
            dungeons[i][1] = fatigue_backup;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    exploreDungeons(k, dungeons, 0);
    return maxVisitCount;
}