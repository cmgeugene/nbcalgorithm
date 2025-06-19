#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(std::vector<int> a) {
    int n = a.size();
    // 수별 빈도 확인 : 가지치기용
    map<int, int> frequency;
    for(int x : a) frequency[x]++;
    
    // 빈도 있는 숫자만 추출
    vector<int> values;
    values.reserve(frequency.size());
    for(auto& p : frequency) values.push_back(p.first);
    
    int answer = 0;
    for(int v : values)
    {
        // 교집합이 있어야 함
        // {v, non v} 혹은 {non v, v} 형태
        // 스타 수열의 길이는 위에서 구한 빈도맵*2가 최대값
        int maxLength = frequency[v]*2;
        if(maxLength <= answer) continue;
        
        // 만들 수 있는 쌍 개수
        int pairs = 0;
        int i = 0;
        
        while (i + 1 < n) {
            if (a[i] == v || a[i + 1] == v) {
                pairs++;
                i += 2;  // 이 두 칸을 모두 사용했으니 건너뛴다
            } else {
                i += 1;  // 다음 위치로 이동
            }
        }
        answer = max(answer, pairs * 2);
    }
    
    return answer;
}