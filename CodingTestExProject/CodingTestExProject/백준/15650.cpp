/*
15650
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� 
M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� "�ߺ� ����" M���� �� ����
�� ������ ���������̾�� �Ѵ�.

15649 �������� �ߺ��� ���ܵǴ� �����̴�.
�ߺ��� �����ϱ� ���ؼ� �������� for���� �� �ε����� ������ �Ѱ��־�� �Ѵ�.
����
*/
#include <iostream>
using namespace std;

int N, M;
int visited[9] = { 0, };
int arr[9] = { 0, };

void dfs(int idx, int num)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << '\n';
	}
	for (int i = num; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			arr[idx] = i;
			dfs(idx + 1, i + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(0, 1);
	return 0;
}