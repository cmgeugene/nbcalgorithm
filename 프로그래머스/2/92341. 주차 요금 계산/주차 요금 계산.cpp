#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // 차 번호, 입차시각과 출차 시각 기록
    map<string, vector<int>> recordsMap;
    // 차 번호, 주차 요금 계산
    map<string, int> feeMap;
    
    for(string record : records)
    {
        string carnum = record.substr(6, 4);
        int hh = stoi(record.substr(0,2)) * 60;
        int mm = stoi(record.substr(3,2));
        int parked = hh + mm;
        
        recordsMap[carnum].push_back(parked);
    }
    
    // 기록이 홀수이면 출차하지 않았다는 뜻이므로 1439 추가
    for(auto& record : recordsMap)
    {
        if(record.second.size() % 2 != 0)
        {
            record.second.push_back(1439);
        }
    }
    
    // 차량 번호별 총 주차시간 및 요금 계산
    for(auto record : recordsMap)
    {
        int totalfee = 0;
        int parkedtime = 0;
        for(int i = 0; i < record.second.size() -1 ; i+=2)
        {
            parkedtime += record.second[i+1] - record.second[i];
        }
        // 기본 시간 이하
        if(fees[0] >= parkedtime)
        {
            totalfee += fees[1];
        }
        // 기본 시간 초과
        else if(fees[0] < parkedtime)
        {
            totalfee += 
                fees[1] +
                ((parkedtime - fees[0] + fees[2] - 1) / fees[2]) * 
                fees[3];
        }
        // 차량별 총 요금 계산
        feeMap[record.first] = totalfee;
    }
    
    
    for(auto fee : feeMap)
    {
        answer.push_back(fee.second);
    }
    return answer;
}