/*
n^2 �迭 �ڸ���

https://school.programmers.co.kr/learn/courses/30/lessons/87390

n�� ũ�Ⱑ 10^7�̹Ƿ� ��� ���ؼ� �ڸ��°� �Ұ����غ����� ó���� dp�ΰ� �ʹٰ� ������ ����ǹǷ� �ƴ϶�� �Ǵ��ߴ�.
�׷��� ��Ģ���� ã������ left�� �� ���� ���غ��� right ���� ����غ��Ҵ�. �̶� �� �� �� �ϳ��� ����� ���ٴ� �� �߰��ߴµ�
��� �� �� �� �� ū ���� �ش� ĭ�� ���� �ȴٴ� ���� �˰ԵǾ���.

left���� �������Ѱ��鼭 1�����迭�� ���� ä���ָ� �Ǵ� �����̴�.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int leftCol, leftRow;
    while (true)
    {
        if (left > right)
            break;
        leftCol = left % n + 1; leftRow = left / n + 1;
        answer.push_back(leftCol > leftRow ? leftCol : leftRow);
        left++;
    }
    return answer;
}