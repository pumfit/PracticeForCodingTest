/*
2920 ����

Ǯ�̴� ���� �����Ѵ�� ù �ڸ��� 1,8 �б⸦ ���� �˻��ϴ� ������ ������ Ǯ����
�ƴ� ��� flag ������ �ϴ� isMixed�� mixed�� ��µǰ� �ߴ�.

ª�� Ǫ�� ����� �� ���� �� ���Ҵµ� ���� �ٸ� Ǯ�̸� Ȯ���غ���
count ��� ������ �̿��� +8�̸� ascending -8�̸� descending �Ѵ� �ƴ϶�� isMixed�� ����� �����ߴ�.
*/
#include<iostream>
using namespace std;

int main()
{
	int arr[8];
	bool isMixed = true;
	for (int i = 0; i < 8; i++)
	{
		int n;
		cin >> n;
		arr[i] = n;
	}

	if (arr[0] == 1)
	{
		for (int i = 1; i < 8; i++)
		{
			if (arr[i] != i + 1)
			{
				break;
			}else if (i == 7)
			{
				isMixed = false;
				cout << "ascending";
			}
		}
	}
	else if (arr[0] == 8)
	{
		for (int i = 1; i < 8; i++)
		{
			if (arr[i] != 8 - i)
			{
				break;
			}
			else if (i == 7)
			{
				isMixed = false;
				cout << "descending";
			}
		}

	}
	if(isMixed)
		cout << "mixed";
}