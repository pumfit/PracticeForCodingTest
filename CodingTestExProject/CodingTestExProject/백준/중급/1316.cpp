/*
1316 �׷� �ܾ� üĿ

�̹� īī�� ���� �ڵ��׽�Ʈ�� �ִ� ������ ����� ����ver ��������.

�ظ̴� �κ�
1. �迭 �ʱ�ȭ ���ؼ� ��� �� �̻��ϰ� ���� ��
2. char���� -'a'�� 0���� �� ã�� �� �ణ �ظ̴�. �ƽ�Ű �ڵ� A,a�� �ܿ�� A = 65, a = 97

�߸��� �κ�
1. ��� Ǯ�� �����ϸ鼭 int word[]�� ���� üũ�ϸ鼭 �ؾ��� �س���� ������ �ΰ��� �������.
������ �� ������ �κ� �ִ��� Ȯ������

+ vector< >�� Ǫ�� ��� �����غ��� ����Ǯ�� ��� �� ã�ƺ���
*/

#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	int num = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char s[100];
		int word[26] = {0,};
		int temp = 0;
		scanf("%s", &s);

		for (int j = 0; j < 100; j++)
		{
			int curNum = s[j] - 'a';
			if (curNum >= 0)
			{
				word[curNum]++;
				if (temp != curNum && word[curNum]>1)
				{
					num--;
					break;
				}
			}
			else
			{
				break;
			}
			temp = curNum;
		}
		num++;
	}

	printf("%d", num);
}