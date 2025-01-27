#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(vector<int> row : commands){
        for(int i = row[0]; i <= row[1]; i++){
            temp.push_back(array[i-1]);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[row[2]-1]);
        temp.clear();
    }
    return answer;
}