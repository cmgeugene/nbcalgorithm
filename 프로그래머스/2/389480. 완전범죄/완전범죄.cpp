#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    if(a[0] - a[1] == b[0] - b[1])
        return a[0] / a[1] > b[0] / b[1];
    else
        return a[0] - a[1] > b[0] - b[1];
}

int solution(vector<vector<int>> info, int n, int m) {
   
    sort(info.begin(), info.end(), compare);
    
    int a_sum = 0, b_sum = 0;
    
    for(int i = 0; i < info.size(); i++)
    {
        int a_val = info[i][0];
        int b_val = info[i][1];
        
        if(m - b_sum > b_val)
            b_sum += b_val;
        else if(n - a_sum > a_val)
            a_sum += a_val;
        else
            return -1;
    }
   
    return a_sum;
}