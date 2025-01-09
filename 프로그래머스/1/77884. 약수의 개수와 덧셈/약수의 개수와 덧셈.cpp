#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int> count;
    for(int i = left; i <= right; i++){
        for(int j = 1; j <= i; j++){
            if(i % j == 0)
                count.push_back(j);
        }
        count.size() % 2 == 0 ? answer += i : answer -= i;
        count.clear();
    }
    return answer;
}