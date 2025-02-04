#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int temp = 0;
    int prime = 0;
    for(int i = 0; i < nums.size()-2; i++)
    {
        for(int j = i + 1; j < nums. size()-1; j++)
        {
            for(int k = j + 1; k < nums.size(); k++)
            {
                temp = nums[i] + nums[j] + nums[k];
                
                for(int i = 2; i <= sqrt(temp); i++)
                {
                    if(temp % i == 0) {prime++;}
                }
                if(prime == 0) { answer++; }
                prime = 0;
            }
        }
    }
    return answer;
}