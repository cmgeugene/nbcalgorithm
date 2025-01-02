#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    string str = to_string(n);
    int temp = 0;
    for(int i = 0; i < str.size(); i++){
        num.push_back(str[i] - '0');
    }
    
    for(int i = 0; i < num.size() -1; i++){
        for(int j = i+1; j < num.size(); j++){
            if(num[i] < num[j]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    str.clear();
    for(int i = 0; i < num.size(); i++){
        str.push_back(num[i] + '0');
    }
    answer = stoll(str);
    
    return answer;
}