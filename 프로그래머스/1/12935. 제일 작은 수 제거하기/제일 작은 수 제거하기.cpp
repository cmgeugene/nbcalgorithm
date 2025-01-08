#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int>::iterator it;
    it = min_element(arr.begin(), arr.end());
    arr.erase(it);
    if(arr.empty())
       arr.push_back(-1);
    return arr;
}