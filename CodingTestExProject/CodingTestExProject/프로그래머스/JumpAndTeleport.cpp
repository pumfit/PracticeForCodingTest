/*
https://programmers.co.kr/learn/courses/30/lessons/12980

ó���� ��Ʈ��ŷ�ΰ� DP�ΰ� �ߴµ� N�� 10���̶�淡 �����ߴ�.
����ü���� ���� ã�� ����� ����߰�
���� ���� 2�谡 �ǹǷ� ������� �ɶ����� 2�谡 ����Ǹ� �ǰ� Ȧ�� �ΰ�쿣 1�� ���ϴ� ������� �����ϸ� �ȴ�.
ó���� ��� �����ߴµ� �������� ���� Ǯ���� ��Ȳ�������� ����
*/
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans++;
        }
        n /= 2;
    }
    return ans;
}