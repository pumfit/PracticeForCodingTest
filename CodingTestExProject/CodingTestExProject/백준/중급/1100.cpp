/*
1100 �Ͼ� ĭ

ĭ ũ��� 8*8
�Ͼ�ĭ�� Ȧ�� ���϶� ¦��, ¦�� ���϶� Ȧ��
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num = 0;

	for (int i = 0; i < 8; i++)
	{
		string s;
		cin >> s;
		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; j += 2)
			{
				if (s.at(j) == 'F')
					num++;
			}
		}
		else
		{
			for (int j = 1; j < 8; j += 2)
			{
				if (s.at(j) == 'F')
					num++;
			}
		}
	}
	cout << num;
}