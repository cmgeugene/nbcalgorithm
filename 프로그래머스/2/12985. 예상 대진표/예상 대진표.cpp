#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int round = 1;
    while(n)
    {   
        if(a % 2 == 0 && b == a - 1)
        {
            return round;
        }
        else if(b % 2 == 0 && a == b - 1)
        {
            return round;
        }
        
        a % 2 == 0 ? a/=2 : a = (a + 1) / 2;
        b % 2 == 0 ? b/=2 : b = (b + 1) / 2;
        round++;
    }
}