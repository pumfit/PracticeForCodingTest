/*
1475 ���ȣ
���ȣ�� ������ 0~9���� ���� ����ִ� ��Ʈ�� ��� �ʿ�����
�迭�� ����� �ȿ��� ����ó��

0 ����ó�� ���ϰ� 34�� ������ �ִ밪 ã�� ���� �Ϸ��� �ؼ� ����̳� ������ ����...
6�� 9�� ���� ���� �����ϴ°� ������ �ֿ� ����Ʈ�̴�!
*/
#include<iostream>
using namespace std;

int main()
{
	int a;
	int max = 0;
	int num[10] = { 0, };

	cin >> a;

	if (a == 0)
	{
		num[0]++;
	}
	else
	{
		while (a != 0)
		{
			int n = a % 10 == 9 ?6: a % 10;
			num[n]++;
			a = a / 10;
		}

	}

	num[6] = num[6] % 2 == 0 ? num[6] / 2 : num[6] / 2 + 1;

	for (int i = 0; i < 10; i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}

	}

	cout << max;
}