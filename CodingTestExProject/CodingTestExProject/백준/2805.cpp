/*
2805 ���� �ڸ���
https://www.acmicpc.net/problem/2805

Ǯ�̰� ���������ʾƼ� ��� Ȯ���� ����
���ϴ� ���� ������ �ּ� ���� st = mid�� st���� ��ȭ���� �ʰ� �δ°� ����Ʈ�� �����̴�.
	while (st < ed)
	{
		int mid = (st + ed + 1) / 2;
		if (isCanTimber(mid, ed))
		{
			st = mid; // st ����
		}
		...
���� �̹����� Ǯ�� �������� �� ����� �ϴµ� ���� ���ϴ� �κп���  (1 �� N �� 1,000,000, 1 �� M �� 2,000,000,000) �� N,M�� �Ѵ� �ִ� ���̶��
int ������ �Ѿ �� �־� long long ���� ����ؾ� Ǯ�̰� �����ϴ�.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

bool isCanTimber(int n, int ed)
{
	long long sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] <= n)
			continue;
		sum += v[i] - n;
	}
	cout << "sum : " << sum << ", mid : " << n << ", ed : " << ed << endl;
	return sum >= M;
}

int main() {
	cin >> N >> M;
	int n;
	while (N--)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int st = 0;
	int ed = v[v.size() - 1];
	while (st < ed)
	{
		int mid = (st + ed + 1) / 2;
		if (isCanTimber(mid, ed))
		{
			st = mid; // st ����
		}
		else
		{
			ed = mid - 1;
		}

	}
	cout << st;
	return 0;
}