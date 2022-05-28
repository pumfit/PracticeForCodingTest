/*
15656 N�� M (7)
N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. N���� �ڿ����� ��� �ٸ� ���̴�.

N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�.

�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.
������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.

���� �������� visited�� �湮 ǥ�ø� ���������� �Ǵ� �����̴�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[8] = { 0, };
int selected[8] = { 0, };

void bf(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < M; i++)
			cout << selected[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		selected[idx] = arr[i];
		bf(idx + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	bf(0);
	return 0;
}