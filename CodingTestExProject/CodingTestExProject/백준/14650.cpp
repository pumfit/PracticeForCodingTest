/*
14650 �ȴٺ��� ��õ�� ��

0, 1, 2�� ������ ���� �� �ִ� N�ڸ� 3�� ����� ������ ����ϻ�.

���ڸ����� ���� 3���� �������� ��� 3�� ����̰� N�� �ִ밪�� 9�϶��� 3^9 �̹Ƿ� ��üŽ���� �����ϴٰ� �����Ǿ���.
dfs�� Ǯ�̸� �����Ͽ��� ���� ����ߴ�. �ٸ� Ǯ�̵��� ���� �� dpǮ�̵� �������� �� �� �־���.
���ɸ� ��� �Է��غ��� 1 - 0 ,2 - 2, 3 - 6, 4 - 18 ,5 - 54 �� dp[i] = dp[i-1]*3�� dp������ �� �� �� �ִ�.
dp�� �� �˰� ���� �ű��ߴ� �����̴�.
*/
#include <iostream>
using namespace std;

int N;
int num[10] = { 0, };
int cnt = 0;

void dfs(int idx)
{
	int sum = 0;
	if (idx == N)
	{
		for (int i = 0; i < N; i++)
			sum += num[i];
		if (sum % 3 == 0)
			cnt++;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (idx != 0)
			num[idx] = i;
		else
		{
			if (i == 0)
				continue;
			num[idx] = i;
		}
		dfs(idx + 1);
	}
}

int main() {
	cin >> N;
	dfs(0);
	cout << cnt;
	return 0;
}