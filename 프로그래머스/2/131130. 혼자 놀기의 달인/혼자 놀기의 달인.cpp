#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void recur(int card, int& count, vector<int>& cards, vector<bool>& boxes)
{
    if(boxes[card] == true) return;
    
    boxes[card] = true;
    count += 1;
    recur(cards[card] -1, count, cards, boxes);
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> groups;
    vector<bool> boxes(cards.size(), false);
    
    for(int i = 0; i < cards.size(); i++)
    {
        if(!boxes[i])
        {
            int count = 0;
            recur(i, count, cards, boxes);
            groups.push_back(count);
        }
    }
    
    if(groups.size() < 2) return 0;
    sort(groups.begin(), groups.end(), greater<>());
    answer = groups[0] * groups[1];
    return answer;
}