/*
1735 �м� ��

�� Ǯ��
���� �м� Ǯ�� ó�� ���� �� �� ���� �и��� �ִ������� ���� ��
�ش簪���� �����־ Ǯ���Ͽ���.

gcd �˰����� ������ �����ξ����� ���� Ǯ �� �־��� ����
*/
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	
	int g = gcd(A*D + B * C, B*D);
	cout << (A*D + B * C) / g << " "<<B * D / g;

}