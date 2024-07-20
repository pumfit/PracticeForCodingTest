/*
https://www.acmicpc.net/problem/2493
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    vector<int> result(N, 0);
    stack<int> s;

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && heights[s.top()] < heights[i]) {
            s.pop();
        }

        if (!s.empty()) {
            result[i] = s.top() + 1;
        }

        s.push(i);
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}