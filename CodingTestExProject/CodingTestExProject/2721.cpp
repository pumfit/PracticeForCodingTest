/*
2721 �ﰢ���� ��
n��° �ﰢ��, T(n)�� 1���� n������ ���̴�. T(n) = 1 + ... + n. �̰��� �ﰢ�� ������� ǥ���� �� �ִ�.
������ ���� ���� ���� ����ġ�� �ο��� �ﰢ���� ���� ���� �� �ִ�.
W(n) = Sum[k=1..n; k*T(k+1)]

T(n)= n(n+1)/2 �̹Ƿ�  k*T(k+1)���� (i*(i + 1)*(i + 2)) / 2 ���� ���ϸ� �Ǵ� �����̴�.
������ 300�� �Ѿ�ԵǸ� �ð��� ���� �� �ִ� ����� ������ �����غ��� ���� �� ����.

*/

#include<iostream>
using namespace std;

int main()
{
	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int N;
		int sum = 0;

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			sum += (i*(i + 1)*(i + 2)) / 2;
		}
		cout << sum << endl;
	}
}