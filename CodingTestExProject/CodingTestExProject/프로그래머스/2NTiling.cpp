/*
* 2 x n ≈∏¿œ∏µ
https://programmers.co.kr/learn/courses/30/lessons/12900
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    long long dp[60001] = { 0, };
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    return dp[n];
}