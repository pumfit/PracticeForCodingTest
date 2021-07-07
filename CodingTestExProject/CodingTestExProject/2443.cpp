/*
2443 별찍기6

2442번 반대로 출력하기
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < ((2 * n - 1) / 2) - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * (i + 1) - 1; j++)
		{
			cout << "*";
		}
		if (i != n-1)
			cout << "\n";
	}

	for (int i = n-2; i >= 0; i--)
	{
		cout << "\n";
		for (int j = 0; j < ((2 * n - 1) / 2) - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * (i + 1) - 1; j++)
		{
			cout << "*";
		}
	}
	
}