/*
¶¥µû¸Ô±â
https://school.programmers.co.kr/learn/courses/18/lessons/1880
*/
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[100001][4] = { 0, };
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (j == k)
                    continue;
                dp[i][j] = max(dp[i - 1][k] + land[i][j], dp[i][j]);

            }
        }
    }
    for (int j = 0; j < 4; j++)
    {
        answer = max(dp[land.size() - 1][j], answer);
    }
    return answer;
}