#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> comple;
    for(string& name : completion)
    {
        comple[name]++;
    }
    
    map<string, int> part;
    for(string& name : participant)
    {
        part[name]++;
    }
    
    for(string& name : participant)
    {
        int name_part = part[name];
        int name_comple = comple[name];
        
        if(name_part != name_comple)
        {
            answer = name;
            break;
        }
    }
    
    return answer;
}