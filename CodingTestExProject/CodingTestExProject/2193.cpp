/*
2193 ��ģ��

0�� 1�θ� �̷���� ���� �������� �Ѵ�. �̷��� ������ �� Ư���� ������ ���� �͵��� �ִµ�, �̵��� ��ģ��(pinary number)�� �Ѵ�. ��ģ���� ������ ������ �����Ѵ�.

��ģ���� 0���� �������� �ʴ´�.
��ģ�������� 1�� �� �� �������� ��Ÿ���� �ʴ´�. ��, 11�� �κ� ���ڿ��� ���� �ʴ´�.
���� ��� 1, 10, 100, 101, 1000, 1001 ���� ��ģ���� �ȴ�. ������ 0010101�̳� 101101�� ���� 1, 2�� ��Ģ�� ����ǹǷ� ��ģ���� �ƴϴ�.

N(1 �� N �� 90)�� �־����� ��, N�ڸ� ��ģ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ DP�������� n=0 ���� �����ϰ� ���غ��Ҵ�.
dp[0] = 0 dp[1] = 1 dp[2] = 1 (10) dp[3] = 2 (100,101) dp[4] = 3(1000,1001,1010) ������� �ϸ� ���� ������ �´�.
���� �Ǻ���ġ ������ ����.(+ ���� 0�� ��� �� ���� +2, ���� 1�� ��� �� ���� +1)
��ȭ���� dp[i] = dp[i - 1] + dp[i - 2];�� �ϰ� ������ 90������ long long���� ó���ߴ�.2
*/
#include <iostream>
using namespace std;

long long dp[91] = { 0, };

int main() {
	int n;
	cin >> n;
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	return 0;
}