/*
9084 ����

�츮���� ȭ�����, Ư�� �������� 1��, 5��, 10��, 50��, 100��, 500���� �ִ�. 
�� ������δ� ������ �ݾ��� ���� �� ������ �� ����� ���� ������ ���� �� �ִ�. 
���� ���, 30���� ����� ���ؼ��� 1��¥�� 30�� �Ǵ� 10��¥�� 2���� 5��¥�� 2�� ���� ����� �����ϴ�.

������ ������ �־��� ���� �־��� �ݾ��� ����� ��� ����� ���� ���α׷��� �ۼ��Ͻÿ�.

���� �������� dp ����Ǯ� dp ���ٹ��� ���� ������� �����̰�
1. �־��� �ݾ��� ����� ��� ���
2. ������ ������
3. ��� M���� ���� ������
�� ����ϸ� �Ǵ� �������� �� ����. ���� dp ������ �ڼ��� Ǯ�̴� �Ʒ��� 
https://maybemine.tistory.com/entry/dp-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4-%EB%8F%99%EC%A0%84-9084-%EC%99%B8
*/
#include <iostream>
#include <cstring>
using namespace std;

int T, N, M;
int coins[21];
int dp[10001] = { 0, };

void check()
{
	dp[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = coins[i]; j <= M; j++)
		{
			dp[j] += dp[j - coins[i]];
		}
	}
	cout << dp[M] << endl;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		memset(dp, 0, sizeof(dp));
		memset(coins, 0, sizeof(coins));
		for (int j = 1; j <= N; j++)
			cin >> coins[j];
		cin >> M;
		check();
	}

	return 0;
}