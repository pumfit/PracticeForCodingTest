/*
2145 ���� ����
�־��� ������ �� �ڸ����� ���Ѵ�.
����� �� �ڸ����� �� �� ���� ��Ģ1�� �ݺ��Ѵ�.
(������ �Է��� 0�̸�, 0�� ���� ����� ������� �ʴ´�.)

0�� ���ö� ������ \n �����ϴ� ��� or �ٸ� �ݷʰ� �ֳ�??
�ݷ� main�� while ���� N > 10�� �ƴ� N >= 10�̴�.
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
	while (true)
	{
		int N = 0, SUM = 0;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		else
		{
			while (N >= 10)
			{
				N = sum(N);
			}
			cout << N << "\n";
		}

	}

}