#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int compareword(string word, string target)
{
    int wordlength = word.size();
    int diffcount = 0;
    
    for(int i = 0; i < wordlength; i++)
    {
        if(word[i] != target[i]) diffcount++; 
    }
    
    return diffcount;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> que;
    vector<bool> visited(words.size(), false);
    
    que.push({begin, 0});
    
    while(!que.empty())
    {
        string current = que.front().first;
        int depth = que.front().second;
        que.pop();
        answer++;
        
        if(current == target) return depth;
        
        for(int i = 0; i < words.size(); i++)
        {
            if(!visited[i] && compareword(current, words[i]) == 1) 
            {
                que.push({words[i], depth+1});
                visited[i] = true;
            }
        }
    }
    return 0;
}