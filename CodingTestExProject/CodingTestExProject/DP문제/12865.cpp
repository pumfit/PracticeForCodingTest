/*
12865 ����� �賶
https://www.acmicpc.net/problem/12865

dp[i][j] �ȿ��� �������� �ִ밡 �Ǵ� 
�賶�� ���� ������ �ִ� ���� ��ŭ �迭�� ��Ƶΰ� ���� �� �ִ� �� ���� ���� �Ǵ� �� �Ŀ� 
- �賶�� ���� �� �ִ°�?
	- �賶�� ������ ���� ��� / ���� ���� ��� �� �� �� ū ��츦 �ִ´�.
- ���� �� ���� ��쿡�� ���� ���� �����Եȴ�.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101] = { 0, };
int V[101] = { 0, };
int dp[101][100001] = { 0, };

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= N; i++)// �賶�� ���� �� �ִ� ���� ������ŭ
	{
		for (int j = 1; j <= K; j++)// �賶�� �ִ� ���Ա���
		{
			if (j - W[i] >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);//���� ���� ���� �� ���� ��
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][K];
	return 0;
}