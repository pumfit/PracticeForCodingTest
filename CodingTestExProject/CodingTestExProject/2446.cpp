/*
2446 별찍기9

규칙을 유추하고 별 출력하시오(모래시계모양)
상단 출력하고 하단 생각하기
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