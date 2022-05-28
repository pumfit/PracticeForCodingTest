/*
3049 �ٰ����� �밢��

3���� 0 0
4���� 1 2 1
5���� 2 10 5
6���� 3 18 15
"�밢���� ������"�� �˻��غ��� ������ �������� nC4���� �� �� �־���.
cout<<Factorial(N) / (Factorial(4)*Factorial(N - 4));�� ó���� �����ߴµ�
100�־����� ���� �÷ο찡 �߻��ؼ� �ĺ���̼��� �����ߴ�.
�ﰢ������ �ĺ���̼� Ǫ�� ����� ���÷��� �ش� ����� �޸��ذ��� Ǯ �� �ְ� �ߴ���
100�� �־ ���� �÷ΰ� �߻����� �ʾҰ� ������ ���� �� �־���.
*/
#include<iostream>
using namespace std;

long long memo[101][101] = { 0, };

long long Combination(int n,int r)
{
	if (memo[n][r] != 0)
		return memo[n][r];
	if (memo[n][r] == 0)
		return memo[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r );
}

int main()
{
	int	N;
	cin >> N;
	for (int i = 0; i < 101; i++)
	{
		memo[i][1] = i;
		memo[i][i] = 1;
	}
	if (N < 4)
	{
		cout << 0;
	}
	else if (N == 4)
	{
		cout << 1;
	}
	else
	{
		cout << Combination(N,4);
	}
}