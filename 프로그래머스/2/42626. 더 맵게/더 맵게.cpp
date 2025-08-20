#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int count_mix = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(!pq.empty() && pq.top() < K)
    {
        // 다 섞어봐도 기준 충족 못하는 경우 
        if(pq.size() == 1 && pq.top() < K) return -1;
        
        count_mix++;
        
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int scv = first + (second*2);
        pq.push(scv);
        
        // 최소힙이므로 top()이 K를 넘으면 모든 음식이 기준치 이상
        if(pq.top() >= K) return count_mix;
        
    }
    return count_mix;
}