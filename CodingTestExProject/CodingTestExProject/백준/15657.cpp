/*
15657 N�� M(8)

N���� �ڿ����� �ڿ��� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. N���� �ڿ����� ��� �ٸ� ���̴�.

N���� �ڿ��� �߿��� M���� �� ����
���� ���� ���� �� ��� �ȴ�.
�� ������ �񳻸������̾�� �Ѵ�.
���̰� K�� ���� A�� A1 �� A2 �� ... �� AK-1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.

�� �ٽ� ���ƿ� N�� M ������ - Ǯ�� ������� Ǯ��,
������ - ó���� ���������� visited �˻��ߴµ� ������ ���� �ߺ��� ���� ������. select�� vector�� �����ؼ� depth �������� �־��־ ���� ��� ù��° ���� ������ ������ �ߴ�.
�迭�� ������ ���� depth(�ε��� ����)��� ���� �־��־���Ѵ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int selected[9] = { 0, };

void bt(int depth, int num)
{
	if (M == depth)
	{
		for (int i = 0; i < M; i++)
			cout << selected[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = num; i < N; i++)
	{
		selected[depth] = v[i];
		bt(depth + 1, i);
	}
}

int main() {
	cin >> N >> M;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	bt(0, 0);
	return 0;
}