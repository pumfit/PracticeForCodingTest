/*
14495 �Ǻ���ġ �񽺹����� ����

������ ���´�� �ϸ�Ǵµ� 116���� �� ���ڸ� �Ѵ� �Ǻ���ġ��
int���� �ƴ� long���� �ٲ�����Ѵ�.
�Ǻ���ġ ������ N������ ���� �ڷ��� �����ϱ�
*/
#include <iostream>
using namespace std;
int N;
long long dp[117];
int main() {
	cin >> N;
	dp[1] = dp[2] = dp[3] = 1;
	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[N];
	return 0;
}