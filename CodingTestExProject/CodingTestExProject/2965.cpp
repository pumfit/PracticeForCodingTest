/*
2965 Ļ�ŷ� ������

������ ū ��� �� �� ���� ���ݿ��� ��� �̵����ָ� �Ǵ� ����
������ �𸣰����� while������ �ϳ��ϳ� �� ���ְ� �ִٰ� ä���ϰ���
�����̴ϱ� �������� Ǯ� �ȴٴ� �� ���޾Ҵ�.
	while (!(A == B || B == C))
	{
		if (C - B > B - A)
		{
			A = B;
			B = B + 1;
		}
		else
		{
			C = B;
			B = B - 1;
		}
		count++;
	}
	cout << count-1;
	�� Ǯ� ����ٰ� �� ª�� �Ʒ� �������� �ٽ� �����ϰ� �����.
*/
#include<iostream>
using namespace std;

int main()
{
	int A, B, C;
	int count = 0;
	cin >> A >> B >> C;

		if (C - B > B - A)
		{
			cout << C - B - 1;
		}
		else
		{
			cout << B - A - 1;
		}
}