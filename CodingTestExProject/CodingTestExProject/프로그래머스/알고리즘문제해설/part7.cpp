/*
단어 퍼즐
https://school.programmers.co.kr/learn/courses/18/lessons/1882#
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = -1;

    int dp[20002] = { 0, };
    fill(dp, dp + 20002, 20000);
    for (int j = 0; j < strs.size(); j++)
    {
        int idx = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (strs[j][idx] != t[i])
                break;
            idx++;
        }
        if (idx != strs[j].size())
            continue;
        dp[strs[j].size() - 1] = 1;
    }

    for (int i = 0; i < t.size(); i++)
    {
        for (int j = 0; j < strs.size(); j++)
        {
            if (strs[j].size() > i + 1)//인덱스보다 큰 경우는 패스
                continue;
            int idx = i;
            for (int k = strs[j].size() - 1; k >= 0; k--)
            {
                if (strs[j][k] != t[idx])
                    break;
                idx--;
            }
            if (strs[j].size() != i - idx)//같지않으면 패스
                continue;

            dp[i] = min(dp[i], dp[i - strs[j].size()] + 1);
        }
    }

    answer = dp[t.size() - 1] == 20000 ? -1 : dp[t.size() - 1];

    return answer;
}