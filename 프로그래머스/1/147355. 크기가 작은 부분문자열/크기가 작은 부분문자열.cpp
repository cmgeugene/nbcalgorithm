#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int p_size = p.size();
    for(int i = 0; i <= t.size() - p_size; i++){
        if(stoll(t.substr(i, p_size)) <= stoll(p))
            answer++;
    }
    return answer;
}