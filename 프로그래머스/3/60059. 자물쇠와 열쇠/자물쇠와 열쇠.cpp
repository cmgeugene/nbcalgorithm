#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotatekey(const vector<vector<int>>& key, int rotatecount)
{
    int M = key.size();
    vector<vector<int>> newkey = key;
    
    for(int r = 0; r < rotatecount; r++)
    {
        vector<vector<int>> temp_key(M, vector<int>(M));
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < M; j++)
            {
                temp_key[j][M - 1 - i] = newkey[i][j];
            }
        }
        newkey = temp_key;
    }
    
    return newkey;
}

bool doeskeyfit(const vector<vector<int>>& expanded, const int& keysize, const int& locksize)
{
    bool fit = true;
    
    for(int i = keysize; i < keysize + locksize; i++)
    {
        for(int j = keysize; j < keysize + locksize; j++)
        {
            if(expanded[i][j] != 1)
            {
                return false;
            }
        }
    }
    return fit;
}

void trytounlock(const vector<vector<int>>& key, vector<vector<int>>& lock, const int& keysize, const int& x, const int& y)
{
    for(int i = 0; i < keysize; i++)
    {
        for(int j = 0; j < keysize; j++)
        {
            lock[y + i][j + x] += key[i][j];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int keysize = key.size(), locksize = lock.size();
    int expanded_lock = keysize + locksize + keysize;
    vector<vector<int>> expanded(expanded_lock, vector<int>(expanded_lock, 0));
    
    // 확장된 자물쇠 중앙에 lock 이식
    for(int i = 0; i < locksize; i++)
    {
        for(int j = 0; j < locksize; j++)
        {
            expanded[i+keysize][j+keysize] = lock[i][j];
        }
    }
    
    // 완전 탐색
    for(int r = 0; r < 4; r++)
    {
        vector<vector<int>> current_key = rotatekey(key, r);
        
        for(int y = 0; y < expanded_lock - keysize + 1; y++)
        {
            for(int x = 0; x < expanded_lock - keysize + 1; x++)
            {
                vector<vector<int>> temp_board = expanded;
                
                trytounlock(current_key, temp_board, keysize, x, y);
                
                if(doeskeyfit(temp_board, keysize, locksize))
                {
                    return true;
                }
                
            }
        }
    }
    
    return answer;
}