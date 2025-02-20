#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer(players.size());
    unordered_map<string, int> name_rank;
    unordered_map<int, string> rank_name;

    for(int i = 0; i < players.size(); i++) {
        name_rank[players[i]] = i;
        rank_name[i] = players[i];
    }

    for(string call : callings) {
        int calledplayerrank = name_rank[call];
        string calledplayername = call;
        string frontplayername = rank_name[calledplayerrank-1];

        name_rank[call]--;
        rank_name[calledplayerrank-1] = call;

        name_rank[frontplayername]++;
        rank_name[calledplayerrank] = frontplayername;
    }

    for(int i = 0; i < rank_name.size(); i++) {
        answer[i] = rank_name[i];
    }
    return answer;
}
