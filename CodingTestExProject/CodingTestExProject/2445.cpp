/*
2445 �����8

��Ģ�� �����ϰ� �� ����Ͻÿ�
��� ����ϰ� �ϴ� �����ϱ�
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < 2*(n - i - 1); j++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		if(i!=n-1)
			cout << "\n";
	}
	for (int i = 0; i < n-1; i++)
	{
		cout << "\n";
		for (int j = 0; j < n - 1 - i ; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < 2 * (i + 1); j++)
		{
			cout << " ";
		}
		for (int j = 0; j < n - 1 - i; j++)
		{
			cout << "*";
		}

	}
}