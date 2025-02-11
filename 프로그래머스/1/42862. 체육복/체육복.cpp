#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // 여벌을 가져온 학생인지부터 판단 find(i)
    // 인덱스 i번이 수업을 들을 수 있는지 벡터에 find(i+1), find(i-1)이 잡히고 값이 2면 
    // 전체 학생을 담은 배열, 값은 체육복 수로
    vector<int> students(n+1, 1);
    for(int student_num : lost)
    {
        students[student_num]--;
    }
    for(int student_num : reserve)
    {
        students[student_num]++;
    }
    
    for(int i = 0; i < students.size(); i++)
    {
        if(students[i] == 0)
        {
            if(students[i-1] == 2)
            {
                students[i-1]--;
                students[i]++;
            }
            else if(students[i+1] == 2)
            {
                students[i+1]--;
                students[i]++;
            }
        }
    }
    answer = count(students.begin(), students.end(), 1) + count(students.begin(), students.end(), 2) - 1;
    return answer;
}