#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    // 사전순으로 가장 앞에 나오는 문자열 = 작음
    // 0은 앞으로 1은 뒤로 밀어야 함
    
    for(string str : s)
    {
        int count = 0;
        string buffer = "";
        
        for(char c : str)
        {
            buffer.push_back(c);
            int n = buffer.size();
            
            if(n >= 3 && buffer[n-3] == '1' && buffer[n-2] == '1' && buffer[n-1] == '0')
            {
                buffer.erase(n-3,3);
                count++;
            }
        }
        
        int lastzeroPos = buffer.find_last_of('0');
        string insertStr = "";
        for(int i = 0; i < count; i++)
        {
            insertStr += "110";
        }
        
        string result = "";
        if(lastzeroPos == std::string::npos)
        {
            result = insertStr + buffer;
        }
        else
        {
            result  = buffer.substr(0, lastzeroPos + 1)
                    + insertStr
                    + buffer.substr(lastzeroPos + 1);
        }
        answer.push_back(result);
    }
    return answer;
}