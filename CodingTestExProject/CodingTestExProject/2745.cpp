/*
2745 ���� ��ȯ

��Ǯ��
N������ ���ڸ� 10�������� �ٲٴ� ����� �ڸ������� N�� ���� �ڸ��� ������ ���� ���ϸ� 10�������� ǥ���� �� �ִ�.
�̸� �̿��Ͽ� Ǯ�̸� �����ϰ��� �Ѵ�.

Ǯ���� �ٸ� Ǯ�̵鵵 ���캸�Ҵµ� ���̽� Ǯ���� ��� ������ �����ϰ� ���������� Ǯ�̰� ª�Ҵ�.
���Ŀ� ���̽����ε� Ǯ���� �������� �ٲ㼭 Ǯ����� ���� �� ����.

+) �ƽ�Ű �ڵ�ǥ ���� �ʰ� Ǯ����Ѵ�.
�⺻���� �ڵ尪�� �ܿ�����
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string N;
	int B;
	long long ans = 0;
	cin >> N >> B;

	for (int i = N.length()-1;  0 <= i ; i--)
	{
		int num = 0;
		if ('A' <= N[i] && N[i] <= 'Z')
		{
			num = N[i] - 'A' + 10;
			for (int j = 0; j < N.length() - i - 1; j++)
			{
				num *= B;
			}
		}
		else
		{
			num = N[i] -48;
			for (int j = 0; j < N.length() - i - 1; j++)
			{
				num *= B;
			}
		}
		ans += num;
	}

	cout << ans;
}