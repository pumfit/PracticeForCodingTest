/*
행렬 테두리 회전하기

https://school.programmers.co.kr/learn/courses/30/lessons/77485

19번에 temp를 x1 x2 로 해두고 로직에 문제 생겼나 계속 보고 왜지??하다가 시간 엄청 빼앗겼다..
시계방향 회전 문제로 
for문을 각 방향 별로 반대로 돌면서 해당 방향 값으로 현재값을 수정해 나가면 된다.
for문의 인덱스는 탐색 방향으로 회전 방향과 반대로 진행된다.

이때, 진행하다보면 마지막의 x1,y1+1 값이 이미 변경된 값으로 채워지기 때문에 먼제 저장해둔 x1,y1 값으로 변경해주면된다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int procession[105][105] = { 0, };

int Move(int x1, int y1, int x2, int y2)
{
    int temp = procession[x1][y1];
    int minNum = temp;

    for (int i = x1; i < x2; i++)//→
    {
        minNum = min(minNum, procession[i][y1]);
        procession[i][y1] = procession[i + 1][y1];
    }
    for (int i = y1; i < y2; i++)//↑
    {
        minNum = min(minNum, procession[x2][i]);
        procession[x2][i] = procession[x2][i + 1];
    }
    for (int i = x2; i > x1; i--)//←
    {
        minNum = min(minNum, procession[i][y2]);
        procession[i][y2] = procession[i - 1][y2];
    }
    for (int i = y2; i > y1; i--)//↓
    {
        minNum = min(minNum, procession[x1][i]);
        procession[x1][i] = procession[x1][i - 1];
    }
    procession[x1][y1 + 1] = temp;
    return minNum;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int cnt = 1;
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < columns; y++)
        {
            procession[x][y] = cnt++;
        }
    }

    for (int i = 0; i < queries.size(); i++)
        answer.push_back(Move(queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1));

    return answer;
}