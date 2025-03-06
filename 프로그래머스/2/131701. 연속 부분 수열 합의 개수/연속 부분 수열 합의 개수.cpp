#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    // 원형이므로 2배
    vector<int> expanded(elements.begin(), elements.end());
    expanded.insert(expanded.end(),elements.begin(), elements.end());
    // 합을 set에 더하여 중복 제거 후 크기 반환
    set<int> sums;
    
    // 원형 수열 순회
    for(int i = 0; i < size; i++)
    {
        int sum = 0;
        // 길이가 j~size() 인 연속 부분수열의 합 구하기
        for(int j = 1; j <= size; j++)
        {
            sum += expanded[i+j-1];
            sums.insert(sum);
        }
    }
    answer = sums.size();
    return answer;
}