/*
2506�� �������

������ Ǯ� �� �ִ� ���� ��Ÿ��

		if (b == 0)
		{
			num = 0;
		}
		else
		{
			num++;
		}
		
		�κ��� ���׿����ڷ� �ٿ��� num = b == 0 ? 0 : num + 1; �� ��ħ

*/

#include<iostream>

using namespace std;

int main()
{
	int n,score=0,num=0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;

		num = b == 0 ? 0 : num + 1;
		score += num;
	}

	cout << score;
}