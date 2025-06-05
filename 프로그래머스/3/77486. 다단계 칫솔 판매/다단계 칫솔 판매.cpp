#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    vector<int> answer;
    
    // key : 조직원 이름
    // value : 조직원을 가입시킨 사람, 조직원이 가입시킨 사람1, 사람2, 사람3
    map<string, vector<string>> graph;
    for(int i = 0; i < n; i++)
    {
        graph[enroll[i]].push_back(referral[i]);
        if(graph.count(referral[i]))
        {
            graph[referral[i]].push_back(enroll[i]);
        }
    }
    
    // 이익 계산
    // key 이름 , value 이익
    map<string, int> result;
    int price = 100;
    int profit = 0;
    
    for(int i = 0; i < seller.size(); i++)
    {
        profit = amount[i] * price;
        string name = seller[i];
        
        // 위까지 도달하는 계산 필요
        while(name != "-" && profit > 0)
        {
            int passup = profit / 10;
            result[name] += (profit - passup);
            name = graph[name][0];
            profit = passup;
        }
    }
    
    for(auto& name : enroll)
    {
        answer.push_back(result[name]);
    }
    
    return answer;
}