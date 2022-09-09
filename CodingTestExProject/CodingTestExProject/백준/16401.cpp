/*
16401 ���� �����ֱ�
https://www.acmicpc.net/problem/16401

ó���� ������ ���ظ� ���ߴ�. �� ���� �׳� ���ؼ� �ο������ ������ �Ǵ� �� �ƴѰ� ������
"��, ���� ���ڴ� ���̿� ������� ���� �������� ������ �� ������, ���ڸ� �ϳ��� ��ĥ ���� ����. " �ϳ��� ��ĥ ���� ���ٴ� ������ ������ �ִ�.
�� 10 10 15���� 15�� 7,7������ ��������.

�̺�Ž������ ���� ���� ã�� �� ���� �ο�����ŭ �߶����� �� Ȯ���ϴ� �ΰ��� �������� �����ϸ�ȴ�.
�̶� �ִ밡 �Ǵ� ���� ã�ƾ��ϹǷ� ed���� ����ϸ�ȴ�.
���� ���� ��쿡�� ed�� 0�� �ǹǷ� ���� ���� ó������ �ʾƵ� �ȴ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, sum = 0;
vector<int> v;

bool IsCanShare(int n)
{
	int target = 0;
	for (int i = 0; i < M; i++)
	{
		int sum = v[i];
		while (sum - n >= 0)
		{
			sum -= n;
			target++;
			if (target == N)
				break;
		}
		if (target == N)
			break;
	}
	return target >= N;
}

int main() {
	int n;
	cin >> N >> M;
	int st = 0;	int ed = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> n;
		sum += n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	ed = v[v.size() - 1];
	int mid = 0;
	while (st <= ed)
	{
		mid = (st + ed) / 2;
		if (IsCanShare(mid))
		{
			st = mid + 1;
		}
		else
		{
			ed = mid - 1;
		}
	}

	cout << ed;
	return 0;
}