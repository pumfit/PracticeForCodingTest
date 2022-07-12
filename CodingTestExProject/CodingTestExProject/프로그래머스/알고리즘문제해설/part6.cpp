/*
스티커 모으기
https://school.programmers.co.kr/learn/courses/18/lessons/1881
*/
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    int dp1[100001] = { 0, };
    int dp2[100001] = { 0, };
    if (n == 1)
        return sticker[0];
    dp1[0] = sticker[0]; dp1[1] = dp1[0];
    int a = 0; int b = 0;
    for (int i = 2; i < sticker.size() - 1; i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }
    dp2[0] = 0; dp2[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }
    answer = max(dp1[n - 2], dp2[n - 1]);

    return answer;
}