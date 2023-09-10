/*
�ĵ��� ����

DP����
�ʱⰪ dp[1] dp[2] dp[3] = 1
��ȭ�� dp[i] = dp[i-2]+dp[i-3];

�ѹ� Ʋ�ȴ� ����
int�� �迭 �����صξ��µ� dp������ ��� N���� Ŀ�� ���� �� ���� ��û Ŀ���� long long���̾���Ѵ�.
100�־�� �����÷� ���°� ���� �ٷ� ����
*/
#include <iostream>
using namespace std;

int main() {
	int T, N;
	long long dp[101] = { 0, };
	cin >> T;
	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	for (int i = 4; i <= 100; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	while (T--)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}