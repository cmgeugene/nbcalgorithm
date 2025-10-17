#include <string>
#include <set>
#include <algorithm>

using namespace std;

int solution(string dirs) {
    pair<int, int> current_pos = {0, 0};
    set<pair<pair<int, int>, pair<int, int>>> history;
    for(const char& dir : dirs)
    {
        pair<int, int> next_pos = current_pos;
        
        if(dir == 'U') next_pos.second++;
        else if(dir == 'D') next_pos.second--;
        else if(dir == 'R') next_pos.first++;
        else if(dir == 'L') next_pos.first--;
        
        if (next_pos.first < -5 || 
        next_pos.first > 5 || 
        next_pos.second < -5 || 
        next_pos.second > 5) continue; 
        
        pair<int, int> start = current_pos;
        pair<int, int> end = next_pos;
        
        if (start > end) swap(start, end);
        
        history.insert({start, end});

        current_pos = next_pos;
    }
    
    return history.size();
}