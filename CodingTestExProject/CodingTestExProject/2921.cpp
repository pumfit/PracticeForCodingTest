/*
2921 ���̳�
��ø for���� ���� �������� �ߺ��� ���ֱ�
*/
#include<iostream>
using namespace std;

int main()
{
	int x;
	int sum = 0;

	cin >> x;

	for (int i = x; i > 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			sum += (i + j);
		}
	}

	cout << sum;
}
