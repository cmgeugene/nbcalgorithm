#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int BFS(int x, int y, int n)
{
    int calculationcount = 0;
    queue<int> que;
    set<int> visited;
    que.push(x);
    visited.insert(x);
    while (!que.empty())
    {
        int currentlevelsize = que.size();
        for(int i = 0; i < currentlevelsize; i++)
        {
            int currentnode = que.front();
            que.pop();
            
            if (currentnode == y) return calculationcount;
            if (currentnode > y) continue;
            
            int nextnode1 = currentnode + n;
            int nextnode2 = currentnode * 2;
            int nextnode3 = currentnode * 3;
            
            if (visited.count(nextnode1) == 0)
            {
                que.push(nextnode1);
                visited.insert(nextnode1);
            }
            if (visited.count(nextnode2) == 0)
            {
                que.push(nextnode2);
                visited.insert(nextnode2);
            }
            if (visited.count(nextnode3) == 0)
            {
                que.push(nextnode3);
                visited.insert(nextnode3);
            }
        }
        calculationcount++;
    }
    return -1;
}

int solution(int x, int y, int n) {
    return BFS(x, y, n);
}