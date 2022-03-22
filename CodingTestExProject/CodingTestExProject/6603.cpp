/*
6603 �ζ�

���� �ζǴ� {1, 2, ..., 49}���� �� 6���� ����.
�ζ� ��ȣ�� �����ϴµ� ���Ǵ� ���� ������ ������ 49���� �� �� k(k>6)���� ���� ��� ���� S�� ���� ���� �� ���� ������ ��ȣ�� �����ϴ� ���̴�.
���� ���, k=8, S={1,2,3,5,8,13,21,34}�� ��� �� ���� S���� ���� �� �� �ִ� ����� ���� �� 28�����̴�. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
���� S�� k�� �־����� ��, ���� ���� ��� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

n�� �� 6���� �ε����� ���ϸ� �Ǵ� �����̰�
visited�� üũ�ϰ� Ǯ��
���� �����ʴ� ������ ���� ������ ���� ������ ū ���� Ȯ�� �� �� �ִµ� �̴� �ε����� ���� �� �����Ƿ�
��½ÿ� �迭�� Ȯ���ϸ鼭 �� ���� ���� �� ū�� Ȯ���Ѵ�.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[15] = { 0, };
int ans[15] = { 0, };
int visited[15] = { 0, };

void bf(int idx) {
	if (idx == 6)
	{
		bool flag = true;
		int tmp = -1;
		//���� ���� �� ū ���� �����Ѵ�.
		for (int i = 0; i < 6; i++)
		{
			if (tmp > arr[ans[i]])
				flag = false;
			tmp = arr[ans[i]];
		}
		if (flag) {
			for (int i = 0; i < 6; i++)
			{
				cout << arr[ans[i]] << " ";
			}
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			ans[idx] = i;
			bf(idx + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	while (true)
	{
		cin >> n;
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		memset(visited, 0, sizeof(visited));
		bf(0);
		cout << '\n';
	}
	return 0;
}