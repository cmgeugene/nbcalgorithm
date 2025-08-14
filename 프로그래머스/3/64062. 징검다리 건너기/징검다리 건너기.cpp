#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1, right = 200000000;
    int mid = 0;
    
    while(left <= right)
    {
        int weakstones = 0;
        bool cancross = true;
        mid = (left + right) / 2;
        
        for(int stone : stones)
        {
            if(stone < mid)
            {
                weakstones++;
            }
            else
            {
                weakstones = 0;
            }
            
            if(weakstones >= k)
            {
                cancross = false;
                break;
            }
        }
        
        if(cancross)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid -1;
        }
        
    }
    
    return answer;
}