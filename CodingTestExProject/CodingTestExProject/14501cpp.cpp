/*
14501 ���
*/
#include <iostream>
#include <algorithm>
using namespace std;

int dp[16] = { 0, };//�� ���� ������ �ִ� ����

int main() {
	int N, m = 0;
	cin >> N;
	for (int i = 1; i <= N + 1; i++)
	{
		int A, B;
		cin >> A >> B;
		if (i + A <= N + 1)
		{
			dp[i + A] = max(dp[i + A], dp[i] + B);
			m = max(m, dp[i + A]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);//���� ���� ���� ���
	}
	cout << m;
	return 0;
}