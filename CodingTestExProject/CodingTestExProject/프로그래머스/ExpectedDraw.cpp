/*
���� ����ǥ
https://school.programmers.co.kr/learn/courses/30/lessons/12985

N�� �� �ʿ��Ѱ��� �𸣰ڴ�
ó���� ���� 1�� �����ϰ� �� ���� ���̰� 1�̸� Ż���ϵ��� ������ �־����� 4������ ���ɰ� Ʋ�ȴ�.
�� ���� ���� 1�϶� 34 �̷��� �ǹ����� ���� ���� �ƴ��� �����ϰ� Ǯ������. �׷��� ���� �Ѵܰ� ������ �� ���� �������� �̷��� ó���ϸ� ���� �ʱ� answer���� 1�� �������� �ʾƵ� �ǰڴ� �;
�����ϰ� �����غ��Ҵ��� ��� ����Ͽ���.
*/
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while (true)
    {
        if (a == b)
            break;
        a = a % 2 == 0 ? a / 2 : a / 2 + 1;
        b = b % 2 == 0 ? b / 2 : b / 2 + 1;
        answer++;
    }

    return answer;
}