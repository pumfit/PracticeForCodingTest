/*
2522�� ����� - 12
 
 �Է°� 3�϶�
  * 
 **
***
 **
  *
  " "���� n-1 ~0���� "*" 1���� n����

*/

#include<iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < i+1 ; j++)
		{
			cout << "*";
		}
		if (i != n - 1)
			cout << "\n";
	}
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			cout << "\n";
		for (int j = 0; j < i + 1; j++)
		{
			cout << " ";
		}
		for (int j = 1; j < n - i; j++)
		{
			cout << "*";
		}
	}
}