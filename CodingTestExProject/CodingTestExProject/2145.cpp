/*
2145 ���� ����
�־��� ������ �� �ڸ����� ���Ѵ�.
����� �� �ڸ����� �� �� ���� ��Ģ1�� �ݺ��Ѵ�.
(������ �Է��� 0�̸�, 0�� ���� ����� ������� �ʴ´�.)

0�� ���ö� ������ \n �����ϴ� ��� or �ٸ� �ݷʰ� �ֳ�??
*/

#include<iostream>
using namespace std;

int sum(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10; //3+7
		n = n / 10;//67 6
	}
	
	return sum;
}


int main()
{
	int N = -1;
	while (N != 0)
	{
		int SUM = 0;
		scanf_s("%d", &N);

		while (N > 10)
		{
			N = sum(N);
		}
		if(N != 0)
			printf_s("%d\n", N);
	}

}