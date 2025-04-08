#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int convert(string input)
{
    int hour = stoi(input.substr(0,2));
    int minute = stoi(input.substr(3,2));
    int converted = (hour * 60) + minute;
    
    return converted;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    
    // 입실시간 빠른 순으로 정렬
    sort(book_time.begin(), book_time.end());
    
    // 정렬된 배열 순회
    for(auto& reserv : book_time)
    {
        int endtime = convert(reserv[1]);
        int starttime = convert(reserv[0]);
        int cleanroom = 10;
        
        // 퇴실이 가장 빠른 방이 다음 예약전에 퇴실한다면
        if(!pq.empty() && pq.top().first <= starttime)
        {
            pq.pop();
        }
        
        // 입실 처리
        pq.push({endtime + cleanroom, starttime});
        
        // 최대 방 수 갱신
        int rooms = pq.size();
        answer = max(answer, rooms);
    }
    
    return answer;
}