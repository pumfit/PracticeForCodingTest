/*
1934 �ּҰ����

��Ŭ���� ȣ����
�Է����� �� �� m,n(m>n)�� ���´�.
n�� 0�̶��, m�� ����ϰ� �˰����� �����Ѵ�.
m�� n���� ������ ��������, n�� ����ϰ� �˰����� �����Ѵ�.
�׷��� ������, m�� n���� ���� �������� ���Ӱ� m�� �����ϰ�, m�� n�� �ٲٰ� 3������ ���ƿ´�.

*/

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	int N;
	int A, B;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		cout << A * B / gcd(A, B)<<endl;
	}
}