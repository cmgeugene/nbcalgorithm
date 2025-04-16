#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    // col 전달을 위해 람다 사용자 정렬 함수 사용
    sort(data.begin(), data.end(), 
        [col](const vector<int>& a, const vector<int>& b) 
        {
            int i = col - 1;
            if (a[i] == b[i]) return a[0] > b[0];
            return a[i] < b[i];
        }
    );
    
    for(int i = row_begin - 1; i < row_end; i++)
    {
        int S_i = 0;
        for(int j = 0; j < data[i].size(); j++)
        {
            S_i += data[i][j] % (i+1);
        }
        answer ^= S_i; 
    }
    
    return answer;
}