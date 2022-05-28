/*
1629 ����

�������� Ư���� ����Լ��� ���� ����
������ ¦���� ��� ������ ������Ģ�� ���� ���� ���� ������ �� ������ ����������
������ Ȧ���� ��쿡�� ��� ó���� ���־�� �ϴ� �� ���� �� ��Ҵµ� ���� ��� ���� a���� ���� �ٽ� �����ָ� �Ǵ� �� �� �ű��߰�
��ͷ� ������ �ް� �ش� ���� �Ǵ��ϴ� ���� ��� �� �־���.

���� ����:
https://youtu.be/8vDDJm5EewM
*/

#include <iostream>
using namespace std;

int Pow(long long a, long long b, long long c)
{
	if (b == 1)//������ 1�� ���
		return a % c;

	long long value = Pow(a, b / 2, c);
	value = value * value % c; //����� ¦���� ����� ������ ���� ��� �ȴ�.

	if (b % 2 == 0)//������ 2�� ����� ���
		return value;
	else
		return value * a % c;//������ 1�� �ƴϸ� 2�� ����� �ƴѰ��
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << Pow(a, b, c);
	return 0;
}