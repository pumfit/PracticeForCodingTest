/*
14569 �ð�ǥ ¥��
https://www.acmicpc.net/problem/14569

50���� �Ѿ�� int�δ� �Ұ����� ���̶�� ������ ��� long long���� ����Ǯ�̸� �����ߴ�.
�ð�ǥ�� ���� �ð��� &������ ���� �ð�ǥ���� ���� �� ���ϸ� �Ǵµ�
�̻��ϰԵ� ������ ������ 2�� ��ӳ��Դ�.

�� ��� �� �����÷ο찡 �߻��ϴ� ���� Ȯ���ߴµ� ��� �߻��ϴ°��� ���� ���� �ᱹ �˻��� �����ߴ�.
������ ��Ʈ �� ������ �����Ҷ� 1<<n �̺κп��� int���̶� 41�� ���� ���� ���� �����÷ΰ� �߻��ϴ� ���̿���
�̺κ��� ������ ����� �� �־���.
*/
#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;
	vector<unsigned long long> v;

	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		int n; unsigned long long num = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> n;
			num |= (1ull << n);
		}
		v.push_back(num);
	}
	cin >> M;
	while (M--)
	{
		int K;
		cin >> K;
		int n; unsigned long long left = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> n;
			left |= (1ull << n);
		}
		bool isPossible;
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (v[i] == (v[i] & left))
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}