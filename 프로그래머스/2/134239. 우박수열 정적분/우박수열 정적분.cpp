#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    // 수열 계산
    int _k = k;
    vector<int> prog;
    prog.push_back(_k);
    while(_k != 1)
    {
        if(_k % 2 == 0)
        {
            _k /= 2;
            prog.push_back(_k);
        }
        else if(_k % 2 != 0)
        {
            _k = _k * 3 + 1;
            prog.push_back(_k);
        }
    }
    
    // x에 따라 구간별 사다리꼴 넓이 계산
    vector<double> trapezoids;
    for(int i = 0; i < prog.size()-1; i++)
    {
        double area = 0;
        area = (prog[i] + prog[i+1]) * 1 / 2.0;
        trapezoids.push_back((double)area);
    }
    
    for(auto& range : ranges)
    {
        int start = range[0];
        int end = trapezoids.size() + range[1];
        if(start > end) answer.push_back(-1.0);
        else
        {
            double sum = 0;
            for(int j = start; j < end; j++)
            {
                sum += trapezoids[j];
            }
            answer.push_back(sum);
        }
    }
    return answer;
}