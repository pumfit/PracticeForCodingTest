/*

15655 N�� M (6)

N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. N���� �ڿ����� ��� �ٸ� ���̴�.

N���� �ڿ��� �߿��� M���� �� ����
�� ������ ���������̾�� �Ѵ�.
"�ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�"�̹Ƿ� ���� �������� ��ͳ� �ݺ����� i ���۰��� �������ִ� num�� ����� Ǯ�̸� �����ߴ�.

���� (1),(2)������ �����Ͽ� ���� Ǯ �� �־���.

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

void bf(int idx, int num)
{
	if (M == idx)
	{
		for (int i = 0; i < M; i++)
			cout << selected[i] << " ";
		return;
	}
	for (int i = num; i < N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			selected[idx] = arr[i];
			bf(idx + 1, i);
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
	bf(0, 0);
	return 0;
}