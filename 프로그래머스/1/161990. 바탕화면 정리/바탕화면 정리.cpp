#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minluy = INT_MAX, minlux = INT_MAX;
    int maxrdy = INT_MIN, maxrdx = INT_MIN;

    // S #가 제일 처음 발견되는 인덱스 luy, 가장 앞에 나오는 인덱스 lux
    // E #가 뒤에서 처음 발견되는 인덱스 rdy, 가장 뒤에 나오는 인덱스 rdx
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                minluy = min(minluy, i);
                minlux = min(minlux, j);
                maxrdy = max(maxrdy, i);
                maxrdx = max(maxrdx, j);
            }
        }
    }

    answer.push_back(minluy);
    answer.push_back(minlux);
    answer.push_back(maxrdy + 1);
    answer.push_back(maxrdx + 1);

    return answer;
}
