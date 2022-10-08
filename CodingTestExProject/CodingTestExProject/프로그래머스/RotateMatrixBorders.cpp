/*
��� �׵θ� ȸ���ϱ�

https://school.programmers.co.kr/learn/courses/30/lessons/77485

19���� temp�� x1 x2 �� �صΰ� ������ ���� ���峪 ��� ���� ����??�ϴٰ� �ð� ��û ���Ѱ��..
�ð���� ȸ�� ������ 
for���� �� ���� ���� �ݴ�� ���鼭 �ش� ���� ������ ���簪�� ������ ������ �ȴ�.
for���� �ε����� Ž�� �������� ȸ�� ����� �ݴ�� ����ȴ�.

�̶�, �����ϴٺ��� �������� x1,y1+1 ���� �̹� ����� ������ ä������ ������ ���� �����ص� x1,y1 ������ �������ָ�ȴ�.
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

    for (int i = x1; i < x2; i++)//��
    {
        minNum = min(minNum, procession[i][y1]);
        procession[i][y1] = procession[i + 1][y1];
    }
    for (int i = y1; i < y2; i++)//��
    {
        minNum = min(minNum, procession[x2][i]);
        procession[x2][i] = procession[x2][i + 1];
    }
    for (int i = x2; i > x1; i--)//��
    {
        minNum = min(minNum, procession[i][y2]);
        procession[i][y2] = procession[i - 1][y2];
    }
    for (int i = y2; i > y1; i--)//��
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