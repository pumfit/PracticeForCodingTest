/*
5347 LCM

�� �� a�� b�� �־����� ��, a�� b�� �ּ� ������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�ּҰ������ ���ϴ� ����
�ִ����� ������ �� �־��� ���� ����
gcd �˰��� Ǯ�� ������ ��
1. A�� ū���� ������ �Ѵ�.
2. ������ �������� ���� Ǯ��� �����غ���.
+) �鸸x�鸸�̶� int���ƴ� long���� �ٲ���ϴ� �������� �̰Ͷ����� �ѹ� Ʋ��
*/
#include<iostream>
using namespace std;

long gcd(long a, long b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		long long A, B;
		cin >> A >> B;
		
		long k = A > B ? gcd(A, B) : gcd(B, A);
		cout<< A * B / k<<endl;
	}
	return 0;
}