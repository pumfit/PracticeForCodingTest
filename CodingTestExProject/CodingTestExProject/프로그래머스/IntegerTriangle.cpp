/*
정수 삼각형
https://school.programmers.co.kr/learn/courses/30/lessons/43105

dp문제
양옆 초기화 후 전체 계산
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[501][501] = {0,};
    int height = triangle.size();
    dp[0][0] = triangle[0][0];
    for(int i =1;i<height;i++)
    {
        dp[i][0] = dp[i-1][0]+triangle[i][0];
        dp[i][i] = dp[i-1][i-1]+triangle[i][i];
    }
    for(int i = 1;i<height;i++)
    {
        for(int j = 1;j<i;j++)
        {
            if(dp[i][j]!=0)
                continue;
            dp[i][j] = max(dp[i-1][j-1] + triangle[i][j],dp[i-1][j] + triangle[i][j]);
        }
    }
    for(int i = 0;i<height;i++)
        answer = max(answer,dp[height-1][i]);
    return answer;
}