/*
2446 �����9

��Ģ�� �����ϰ� �� ����Ͻÿ�(�𷡽ð���)
��� ����ϰ� �ϴ� �����ϱ�
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)//0~4
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2*(n-i) - 1; j++)
		{
			cout << "*";
		}
		if(i!=n-1)
			cout << "\n";
	}
	for (int i = 0; i < n - 1; i++)//0~3
	{
		cout << "\n";
		for (int j = 0; j <(2 * n - 2 * i - 3) / 2; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2*(i+2)-1; j++)
		{
			cout << "*";
		}
	}
}