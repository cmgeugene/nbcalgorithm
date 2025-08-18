#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    set<string> bookmap(phone_book.begin(), phone_book.end());
    
    set<string>::iterator iter;
    for(iter = bookmap.begin(); iter != bookmap.end(); iter++)
    {
        string source = *iter;
        string prefix = "";
            
        for(int i = 0; i < source.size(); i++)
        {
            prefix += source[i];
            if(bookmap.count(prefix) > 0 && prefix != source) return false;
        }
    }
    return answer;
}