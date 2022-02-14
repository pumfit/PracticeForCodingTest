/*
11057 ������ ��

������ ���� ���� �ڸ��� ���������� �̷�� ���� ���Ѵ�. �̶�, ������ ���� ���Ƶ� ������������ ģ��.
���� ���, 2234�� 3678, 11119�� ������ ��������, 2232, 3676, 91111�� ������ ���� �ƴϴ�.
���� ���� N�� �־����� ��, ������ ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� 0���� ������ �� �ִ�.

���ڸ��� �̰� DP ������� ������ ��� �ڸ����� ���� �������� ������ ���� ���� �ڸ����� �����Ǿ� ������ �����̴�.

dp[1] = 10 dp[2] = 55 dp[3] = 220 dp 1�� 2�� ���� 1~10�� ���� 55�� ���� �� �� �ִµ�
�̸� ������ �迭 ����ٺ��� dp[i][j] = dp[i][j - 1] + dp[i - 1][j] ��ȭ���� �߰��� �� �ִ�.

ù° �ٿ� ���̰� N�� ������ ���� ������ 10,007�� ���� �������� ����Ѵ�.

+)
10007�����ִ� �� ������ 2�� Ʋ������ 31������ ���ְ� ������ �ϴ� ���������� ������Ѵ�.
ó���� 1000 ���� �־�� �䳪�´ٰ� �ٷ� �� �־��µ� Ʋ������ 1000������ 10007 �Ѵ� �� ���°� Ȯ���� ���ߴ�..�Ǽ� �������� 
*/
#include <iostream>
using namespace std;

int dp[1002][11] = { 0, };
int N;
int sum = 0;

int main() {
	cin >> N;
	for (int i = 1; i <= 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	for (int i = 1; i <= 10; i++)
		sum = (sum + dp[N][i]) % 10007;
	cout << sum;
	return 0;
}