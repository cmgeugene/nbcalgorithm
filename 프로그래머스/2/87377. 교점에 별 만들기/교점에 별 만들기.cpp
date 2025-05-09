#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

pair<long long, long long>getPoint(vector<int>& line1, vector<int>& line2, bool& isValid)
{
    long long A1 = line1[0], B1 = line1[1], C1 = line1[2];
    long long A2 = line2[0], B2 = line2[1], C2 = line2[2];
    
    long long denom = A1*B2 - A2*B1;
    // 평행 또는 일치
    if(denom == 0)
    {
        isValid = false;
        return {0,0};
    }
    
    long long xNume = B1 * C2 - B2 * C1;
    long long yNume = C1 * A2 - C2 * A1;
    
    // 정수 교점만 허용
    if (xNume % denom != 0 || yNume % denom != 0) 
    {
        isValid = false;
        return {0, 0};
    }

    isValid = true;
    return {xNume / denom, yNume / denom};
}

void findAllPoints(vector<vector<int>>& lines, set<pair<long long, long long>>& points, long long& minX, long long& maxX, long long& minY, long long& maxY)
{
    int n = lines.size();
    
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            bool isValid = false;
            pair<long long, long long> p = getPoint(lines[i], lines[j], isValid);
            
            if(isValid)
            {
                points.insert(p);
                
                minX = min(minX, p.first);
                maxX = max(maxX, p.first);
                minY = min(minY, p.second);
                maxY = max(maxY, p.second);
                    
            }
        }
    }
}

vector<string> printStars(set<pair<long long, long long>>& points, long long minX, long long maxX, long long minY, long long maxY) 
{
    long long width = maxX - minX + 1;
    long long height = maxY - minY + 1;

    // '.'로 초기화된 2D 문자열 배열
    vector<string> grid(height, string(width, '.'));

    for (auto& p : points) {
        long long x = p.first;
        long long y = p.second;

        // 좌표 변환
        int row = maxY - y;     
        int col = x - minX;     

        grid[row][col] = '*';
    }

    return grid;
}


vector<string> solution(vector<vector<int>> line) {
    set<pair<long long, long long>> points;
    long long minX = LLONG_MAX, maxX = LLONG_MIN;
    long long minY = LLONG_MAX, maxY = LLONG_MIN;

    // 모든 교점 계산 및 좌표 범위 추적
    findAllPoints(line, points, minX, maxX, minY, maxY);

    // 교점들을 2D 문자열 배열로 변환
    return printStars(points, minX, maxX, minY, maxY);
}