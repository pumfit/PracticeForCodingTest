/*

15654 N�� M (5)

N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. N���� �ڿ����� ��� �ٸ� ���̴�.

N���� �ڿ��� �߿��� M���� �� ����
������ ����� �����ʰ� N���� �ڿ����� ���� ������ ó�� 1~N���� �ڿ����� �����ؼ� ���� �ظ̴�.

arr�� �޾ƿ� �ڿ����� �޾ƿ� �� ������ �ϰ� �����Ͽ� ���� ������ �����ϴ� ������ ��µǰ� �Ͽ���.

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int n;
vector<int> arr;
int selected[9] = { 0, };
int visited[9] = { 0, };

void bf(int idx)
{
	if (M == idx)
	{
		for (int i = 0; i < M; i++)
			cout << selected[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			selected[idx] = arr[i];
			bf(idx + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end());

	bf(0);
	cout << '\n';
	return 0;
}