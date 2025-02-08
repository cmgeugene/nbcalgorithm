#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babblings) {
    int answer = 0;
    string word = "";
    string temp = "";
    vector<string> jb = {""};

    for(string babbling : babblings)
    {
        word.clear();
        temp.clear();
        jb = {""};
        for(int i = 0; i < babbling.size(); i++)
        {
            temp += babbling[i];
            if (temp == "aya" && jb.back() != "aya") 
            {
                word += temp;
                jb.push_back("aya");
                temp = "";
            }
            if (temp == "ye" && jb.back() != "ye")
            {
                word += temp;
                jb.push_back("ye");
                temp = "";
            }
            if (temp == "woo" && jb.back() != "woo")
            {
                word += temp;
                jb.push_back("woo");
                temp = "";
            }
            if (temp == "ma" && jb.back() != "ma")
            {
                word += temp;
                jb.push_back("ma");
                temp = "";
            }
        }
        
        if(word == babbling) answer++;
    }
    return answer;
}