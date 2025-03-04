#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// value 기준 비교 함수, 내림차순
bool compare(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // 크기가 서로 다른 종류의 최솟값
    // 수가 많은 크기부터 담으면 되지 않을까?
    
    // 주어진 배열을 맵으로 옮김
    map<int, int> tangerines;
    for(int i = 0; i<tangerine.size(); i++)
    {
        tangerines[tangerine[i]]++;
    }
    
    // 맵을 벡터로 옮김
    vector<pair<int, int>> sorted(tangerines.begin(), tangerines.end());
    
    // 벡터 내림차순 정렬
    sort(sorted.begin(), sorted.end(), compare);
    
    // 정렬된 벡터의 value를 k와 비교
    int packed = 0;
    for(int i = 0; i < sorted.size(); i++)
    {
        packed += sorted[i].second;
        answer++;
        if(packed >= k)
        {
            break;
        }
    }
    return answer;
}