#include <string>
#include <vector>
#include <set>

using namespace std;

bool IsPrime(string num)
{
    int number = stoi(num);
    if(number < 2) return false;
    for(int i = 2; i * i <= number; i++)
    {
        if(number % i == 0) return false;
    }
    return true;
}

void DFS(vector<pair<string, int>>& num, string currentnum, set<int>& answerset)
{
    if(IsPrime(currentnum)) answerset.insert(stoi(currentnum));
    
    if(currentnum.size() == num.size()) return;
    
    for(int i = 0; i < num.size(); i++)
    {
        if(num[i].second == 0)
        {
            num[i].second = -1;
            DFS(num, currentnum + num[i].first, answerset);
            num[i].second = 0;
        }
    }
}

int solution(string numbers) {
    set<int> PrimeNumbers;
    vector<pair<string, int>> num;
    int answer = 0;
    // DFS냐 BFS냐, 일단 DFS로 풀어보자.
    // 소수를 만들어 set에 stoi로 넣기 -> set size 반환
    // 호출 스택 매 단계에서 소수인지 파악 필요    
    for(auto& t : numbers)
    {
        string buffer = "";
        buffer += t;
        num.push_back(make_pair(buffer,0));
        buffer = "";
    }
    for(int i = 0; i < num.size(); i++)
    {
        num[i].second = -1;
        DFS(num, num[i].first, PrimeNumbers);
        num[i].second = 0;
    }
    answer = PrimeNumbers.size();
    return answer;
}