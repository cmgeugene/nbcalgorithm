#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_binary(long long num)
{
    string s = "";
    while(num)
    {
        s.push_back( (num & 1) ? '1' : '0');
        num >>= 1;
    }
    if(s.empty()) s = "0";
    reverse(s.begin(), s.end());
    return s;
}

string pad_perfect(const string& bin)
{
    size_t str_len = bin.length();
    int h = 0;
    while(((1ULL << h) - 1ULL) < str_len)
        h++;
    
    size_t perfect_len = (1ULL << h) - 1ULL;
    return string(perfect_len - str_len, '0') + bin;
}

bool valid(const string& s)
{
    if (s.length() == 1) return true;        

    size_t mid   = s.length() / 2;          
    char   root  = s[mid];
    string left  = s.substr(0, mid);
    string right = s.substr(mid + 1);       

    // 부모가 더미일 때 자식이 실제일 수 없음
    if (root == '0' &&
        ( left.find('1') != string::npos || right.find('1') != string::npos ))
        return false;

    //재귀 검사
    return valid(left) && valid(right);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    answer.reserve(numbers.size());
    
    for(long long num : numbers)
    {
        string bin = to_binary(num);
        string perfect = pad_perfect(bin);
        bool ok = valid(perfect);
        answer.push_back(ok? 1 : 0);
    }
    return answer;
}