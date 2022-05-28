/*
15651 N�� M(4)

�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�.
�� ������ �񳻸������̾�� �Ѵ�.
���̰� K�� ���� A�� A1 �� A2 �� ... �� AK-1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.

N�� M�� ���� ������� �ش� ������ ���� ���ش� �ߺ��� �񳻸������̴�. visted x
num���� ���� i���� �ǵ��� ����� (3)�� �޸� �ߺ��Ǵ� ������ ���� �� ������� �ʴ´�.
*/
#include<iostream>
using namespace std;

int arr[8] = { 0, };
int visited[8] = { 0, };
int N, M;

void dfs(int idx,int num)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i <= N; i++)
	{
		arr[idx] = i;
		dfs(idx+1, i);
	}
}

int main()
{
	cin >> N >> M;
	dfs(0,1);
	return 0;
}