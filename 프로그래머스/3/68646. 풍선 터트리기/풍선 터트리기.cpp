#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int size = a.size();
    // 남길 수 풍선 양쪽 구역 최솟값 구하기
    vector<int> minLeft(size), minRight(size);
    
    
    // 왼쪽 구역
    minLeft[0] = a[0];
    for(int i = 1; i < size; i++)
    {
        minLeft[i] = min(minLeft[i - 1], a[i]);
    }
    
    // 오른쪽 구역
    minRight[size - 1] = a[size - 1];
    for(int i = size - 2; i >= 0; i--)
    {
        minRight[i] = min(minRight[i + 1], a[i]);
    }
    
    // 남길 수 있는 풍선
    int answer = 0;
    if(size == 1) return 1;
    
    for(int i = 0; i < size; i++)
    {
        if(a[i] <= minLeft[i] || a[i] <= minRight[i]) answer++;
    }
    
    return answer;
}