/*
2442 �����5

Ȧ�� 2n-1
"��� ������ �߸��Ǿ����ϴ�" ó�� ������ ����µ�
������ �ڿ��� ���� �߰��ߴ��� ����� �������.
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < ( (2*n - 1) / 2 )-i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * (i+1) - 1; j++)
		{
			cout << "*";
		}
		if(i!=n-1)
			cout << "\n";
	}
}