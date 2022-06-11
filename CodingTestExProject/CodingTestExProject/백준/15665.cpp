/*
N�� M(11)
https://www.acmicpc.net/problem/15665

N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�.

���� ���� ���� �� ��� �ȴ�.
-> �迭�� 0���� �����Ѵ�.
-> ������ �� ���� �ƴϰ� ó���Ѵ�.(prevNum)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10001];
int ans[10001];
int visited[10001] = { 0, };

void bf(int idx, int num)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << endl;
		return;
	}
	int preNum = -1;
	for (int i = num; i < N; i++)
	{
		if (!visited[i] && preNum != arr[i])
		{
			visited[i] = 1;
			ans[idx] = arr[i];
			preNum = arr[i];
			bf(idx + 1, i);
			visited[i] = 0;
		}

	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	bf(0, 0);
	return 0;
}