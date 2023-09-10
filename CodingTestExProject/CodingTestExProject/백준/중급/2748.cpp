/*
2748 �Ǻ���ġ ��2

ù° �ٿ� n�� �־�����. n�� 90���� �۰ų� ���� �ڿ����̴�.
���� �Ǻ���ġ �� ������ �޸����̼��� �����ϸ鼭 ���� ���� Ŀ int���� long ���� Ÿ���� ��ȯ���־���.
�̶� 19�� ������ else if�� ���� �Ǽ��� �Ͽ��µ� else if�� �ƴ� if�� ��� 0,1��� ���� ������ ����� ����������. ��������
*/
#include <iostream>
using namespace std;

long long Fidata[90] = { 0, };

long long Fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (Fidata[n] == 0)
		Fidata[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
	return Fidata[n];
}
int main()
{
	int N = 0;
	cin >> N;
	cout << Fibonacci(N);
	return 0;
}