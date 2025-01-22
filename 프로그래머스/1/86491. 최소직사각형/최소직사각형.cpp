#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxw = 0;
    int maxh = 0;
    for (auto& row : sizes){
        if(row[0] < row[1]) {swap(row[0],row[1]);}
    }
    int maxvalue = sizes[0][0];
    for (auto& row : sizes){
        if(row[0] > maxvalue){
            maxvalue = row[0];
        }
    }
    maxw = maxvalue;
    maxvalue = sizes[0][1];
    for (auto& row : sizes){
        if(row[1] > maxvalue){
            maxvalue = row[1];
        }
    }
    maxh = maxvalue;

    answer = maxw * maxh;    
    return answer;
}