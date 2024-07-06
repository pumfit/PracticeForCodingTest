/*
https://www.acmicpc.net/problem/15558
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct State {
    int row;
    int col;
    int time;  
};

bool CheckClearGame(int N, int k, const vector<string>& map) 
{
    vector<vector<bool>> visited(2, vector<bool>(N, false));
    queue<State> q;

    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        int row = current.row;
        int col = current.col;
        int time = current.time;

        if (col < time) 
            continue;

        if (col >= N)
            return true;


        if (col + 1 < N && !visited[row][col + 1] && map[row][col + 1] == '1') {
            q.push({row, col + 1, time + 1});
            visited[row][col + 1] = true;
        }


        if (col - 1 >= 0 && !visited[row][col - 1] && map[row][col - 1] == '1') {
            q.push({row, col - 1, time + 1});
            visited[row][col - 1] = true;
        }


        int newCol = col + k;  int newRow = 1 - row;
        if (newCol < N && !visited[newRow][newCol] && map[newRow][newCol] == '1') {
            q.push({newRow, newCol, time + 1});
            visited[newRow][newCol] = true;
        }

        if (newCol >= N) 
            return true;
    }

    return false;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<string> map(2);
    
    for (int i = 0; i < 2; ++i) {
        cin >> map[i];
    }

    if (CheckClearGame(N, K, map))
    {
        cout<<1;
        return 0;
    }
        
    cout<< 0;

    return 0;
}