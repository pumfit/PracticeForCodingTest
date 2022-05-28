/*
11725 Ʈ���� �θ� ã��

Ʈ�� ���� + �ð��ʰ�

�ð��ʰ� ���� '\n' ����ϱ� + ios_base::sync_with_stdio(flase); cin.tie(NULL); cout.tie(NULL);
Ʈ���� ���信 ���ؼ� �� �� �����ϰ� Ʈ���� ��ȸ ������ �� Ǯ��� �� ���� �� ����.
+)
�ش� Ǯ�̴� dfsǮ�� ����ε� bfs�ε� Ǯ����߰ڴ�.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[100001];
int parent[100001] = { 0, };
int N;

void dfs(int n)
{
	for (int i = 0; i < arr[n].size(); i++) //n�� ����� ��� ���
	{
		int next = arr[n][i];//n�� ����� ���
		if (parent[n] == next) //n�� �θ� �̹� ������ ���
			continue;
		parent[next] = n;//����� ����� �θ� n���� �� �� �������� �Ѿ��.
		dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		arr[A].push_back(B);//������ ����� �׷����� ����
		arr[B].push_back(A);
	}
	dfs(1);//1�� ������ dfs ��ȸ
	for (int i = 2; i <= N; i++)//2�� ��� ���� ���
		cout << parent[i] << '\n';
	return 0;
}