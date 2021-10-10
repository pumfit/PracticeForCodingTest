/*
2522번 별찍기 - 12
 
 입력값 3일때
  * 
 **
***
 **
  *
  " "공백 n-1 ~0까지 "*" 1부터 n까지

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