/*
15651 N�� M(3)

�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�.

�ߺ��� ����ϸ� ���� ���� ���� �� ��� �ȴ�. ���� 1,2�� ��������
visited�� ���� ���� ���� Ž���ߴ��� �˻��ϴ� �κ��� �������־ �ȴ�.
*/
#include<iostream>
using namespace std;

int arr[8] = { 0, };
int N, M;

void dfs(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		arr[idx] = i;
		dfs(idx+1);
	}
}

int main()
{
	cin >> N >> M;
	dfs(0);
	return 0;
}