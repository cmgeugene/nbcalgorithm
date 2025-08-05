#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    if(sticker.size() <= 3)
    {
        sort(sticker.begin(), sticker.end());
        return sticker.back();
    }
    
    // 첫 번째 스티커 떼는 경우
    vector<int> first(sticker.size());
    
    // 첫 번째 스티커를 뗐으니 두 번째는 뗄 수 없으므로 first[1]은 first[0]과 같음
    first[0] = sticker[0];
    first[1] = first[0];

    for(int i = 2; i < sticker.size() -1; i++)
    {
        first[i] = max((sticker[i] + first[i-2]), first[i-1]);
    }
    
    int sum_first = first[sticker.size() -2];
    
    // 안 떼는 경우
    vector<int> notfirst(sticker.size());
    // 첫 번째 스티커를 안 뗐으므로 두 번째 원소의 최대값은 sticker[1]
    notfirst[0] = 0;
    notfirst[1] = sticker[1];
    
    for(int j = 2; j < sticker.size(); j++)
    {
        notfirst[j] = max((sticker[j] + notfirst[j-2]), notfirst[j-1]);
    }
    
    int sum_notfirst = notfirst[sticker.size() -1];
    
    return max(sum_first, sum_notfirst);
}