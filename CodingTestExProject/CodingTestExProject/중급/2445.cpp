/*
2445 별찍기8

규칙을 유추하고 별 출력하시오
상단 출력하고 하단 생각하기
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