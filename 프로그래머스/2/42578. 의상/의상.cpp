#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> closet;
    
    for(const auto& clothe : clothes)
    {
        closet[clothe[1]]++;
    }
    
    for(pair<string, int> OOTD : closet)
    {
        answer *= OOTD.second + 1;
    }
    
    return answer - 1;
}