#include <iostream>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int via, vector<vector<int>>& answer) {
    if (n == 1) {
        answer.push_back({ from, to });
        return;
    }
    hanoi(n - 1, from, via, to, answer);
    answer.push_back({ from, to });
    hanoi(n - 1, via, to, from, answer);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);

    cout << answer.size() << '\n';
    for (auto& move : answer)
    {
        cout << move[0] << " " << move[1] << '\n';
    }
    return 0;
}