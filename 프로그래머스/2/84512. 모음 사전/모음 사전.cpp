#include <string>
#include <vector>

using namespace std;

int answer = 0;
int order = -1;
string target = "";
string vowels = "AEIOU";

void DFS(string word)
{
    order++;
    
    if(word == target) 
    {
        answer = order;
        return;
    }
    
    if(word.size() >= 5) return;
    
    for(int i = 0; i < 5; i++)
    {
        DFS(word + vowels[i]);
    }
}

int solution(string word) {
    target = word;
    DFS("");
    return answer;
}