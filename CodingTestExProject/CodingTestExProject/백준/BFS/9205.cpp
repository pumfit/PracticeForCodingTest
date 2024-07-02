/*
https://www.acmicpc.net/problem/9205
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int GetDistance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N; 

        vector<pair<int, int>> list(N + 2); 

        for (int i = 0; i < N + 2; i++)
            cin >> list[i].first >> list[i].second;
        
        queue<int> q;
        vector<bool> visited(N + 2, false);

        q.push(0);
        visited[0] = true;
        bool isCanArrive = false;

        while (!q.empty()) {
            int c = q.front();
            q.pop();

            if (GetDistance(list[c], list[N + 1]) <= 1000) {
                isCanArrive = true;
                break;
            }

            for (int i = 1; i < N + 2; i++) {
                if (!visited[i] && GetDistance(list[c], list[i]) <= 1000) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        if (isCanArrive) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }
    }

    return 0;
}
