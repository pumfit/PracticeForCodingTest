/*
https://www.acmicpc.net/problem/9658
*/
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    bool dp[1001] = {false};

    dp[1] = false;
    dp[2] = true;
    dp[3] = false;
    dp[4] = true;

    for (int i = 5; i <= N; ++i) {
        if (dp[i-1] && dp[i-3] && dp[i-4]) {
            dp[i] = false;
        } else {
            dp[i] = true;
        }
    }

    if (dp[N]) {
        cout << "SK";
    } else {
        cout << "CY";
    }

    return 0;
}