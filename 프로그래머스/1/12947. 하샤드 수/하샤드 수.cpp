#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int l = 0;
    int cpyx = x;
    while(x != 0){
        l = l + x % 10;
        x = x/ 10;
        }
    if(cpyx % l == 0) {answer = true;}
    else {answer = false;}
    return answer;
}