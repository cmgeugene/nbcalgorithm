#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int g;
    int l;
    if(n>m){
        g = n;
        l = m;
    }
    else {
        g = m;
        l = n;
    }
    while(l != 0){
        int temp = l;
        l = g % l;
        g = temp;
    }
    answer.push_back(g);
    answer.push_back(n*m/g);
    
    return answer;
}