/*
2935 ����

ù° �ٿ� ���� ���� A�� �־�����.
��° �ٿ� ������ + �Ǵ� *�� �־�����.
��° �ٿ� ���� ���� B�� �־�����.
A�� B�� ��� 10�� ���� �����̰�, ���̴� �ִ� 100�ڸ��̴�.

������ ó���� �����ָ� �Ǵ� �����̴�. ��� �����ߴµ�..
int main()
{
	int A, B;
	char O;

	cin >> A >> O >> B;

	if (O == '+')
	{
		cout << A + B;
	}
	else
	{
		cout << A * B;
	}
}
���̰� �ִ� 100�ڸ�..100�� �ڸ��� �ƴ϶� 100�ڸ���. ���Ͱ��� int������ ����� �Ұ����ϴ� ������ �ʹ� �����ߴ�. ���⼭ �ѹ� Ʋ�ȴ�.
�׸��� �������� �ڸ����� ���� 55-59�������� ���������ʰ� 70,78�������� for�� �ȿ� �־ �ι� Ʋ�Ⱦ���.
����° �õ��� �Ʒ��� ���� �ڵ�� ����Ͽ���.

+)���̽��� ���� ���ڵ��� �����ϱ��� �ѹ��� ���� ����
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string A, B;
	string ans = "";
	char O;

	std::cin >> A >> O >> B;

	if (O == '+')
	{
		if (A.length() > B.length())
		{
			A[A.length() - B.length()] = '1';
			ans = A;
		}
		else if(A.length() < B.length())
		{
			B[B.length() - A.length()] = '1';
			ans = B;
		}
		else
		{
			A[0] = '2';
			ans = A;
		}

	}
	else
	{
		if (A.length() >= B.length())
		{
			for (int i = 0; i < B.length()-1; i++)
			{
				A = A.append("0");
			}
			ans = A;
		}
		else
		{
			for (int i = 0; i < A.length()-1; i++)
			{
				B = B.append("0");
			}
			ans = B;
		}
	}
	cout << ans;
}