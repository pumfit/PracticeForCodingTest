/*
15666 N�� M (12)

N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�. �� ������ �񳻸������̾�� �Ѵ�.
���̰� K�� ���� A�� A1 �� A2 �� ... �� AK-1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.

�̹� ������ �ֿ� ����Ʈ�� 1,7 �� 7,1�� �ɷ����ϹǷ� i = 0�������� �����ϴ� �� �ƴ� ���� �ε��������� �����ؾ��Ѵ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10] = { 0, };
int arr[10] = { 0, };
void bf(int n, int idx) {
	if (n == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int i = idx; i < N; i++)
	{
		if (prev != num[i])
		{
			prev = num[i];
			arr[n] = num[i];
			bf(n + 1, i);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	bf(0, 0);
	return 0;
}