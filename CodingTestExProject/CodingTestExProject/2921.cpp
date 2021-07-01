/*
2921 도미노
중첩 for문의 범위 지정으로 중복값 없애기
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
