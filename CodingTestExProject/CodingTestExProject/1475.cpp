/*
1475 ���ȣ
���ȣ�� ������ 0~9���� ���� ����ִ� ��Ʈ�� ��� �ʿ�����
�迭�� ����� �ȿ��� ����ó��
+
cin,cout ��뺸�� #include<stdio.h>�� �߰��Ͽ� ����¿� scanf()�� printf()�����
�ͼ��ϰ� ����

#define  _CRT_SECURE_NO_WARNINGS
scanf unsafe ���� ��� (��ó : https://hijuworld.tistory.com/47 )

			for (int i = 0; i < 10; i++)
			{
				num[i] = 0;
			}

*/

#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a;
	int ans,max = 0;
	int num[10] = { 0, };

	scanf("%d \n", &a);

	while (a!=0)
	{
		num[a % 10]++;

		a = a / 10;
	}

	if (num[6] > 1 && num[6] / 2 > num[9])
	{
		while (num[6] / 2 >= num[9])
		{
			num[6]--;
			num[9]++;
		}
	}
	if (num[9] > 1 && num[9] / 2 > num[6])
	{
		while (num[9] / 2 >= num[6])
		{
			num[9]--;
			num[6]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}
		
	}
	ans = max;
	printf("%d \n", ans);
}