#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> reportMap; // [신고당한ID][신고자ID]
    unordered_map<string, int> mailCount; // [유저ID] = 받을 메일 수

    // 1. 리포트 처리
    for (string r : report) 
    {
        int pos = r.find(' ');
        string reporter = r.substr(0, pos);
        string target = r.substr(pos + 1);
        
        reportMap[target].insert(reporter); // set 이라 동일 유저의 중복된 신고는 자동으로 걸러줌
    }

    // 2. 메일 발송 대상 처리
    for (pair<string, unordered_set<string>> pair : reportMap) 
    {
        if (pair.second.size() >= k) 
        {
            for (string reporter : pair.second) 
            {
                mailCount[reporter]++;
            }
        }
    }

    // 5. 결과 생성
    
    for (string id : id_list) 
    {
        answer.push_back(mailCount[id]);
    }
    return answer;
}