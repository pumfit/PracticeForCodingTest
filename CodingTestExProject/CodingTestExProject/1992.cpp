/*
1992 ����Ʈ��

��� ������ �����Ͽ� ǥ���ϴ� ������ ������ ���� Ʈ��(Quad Tree)��� ����� �ִ�. �� ���� ��Ÿ���� 0�� ���� ���� ��Ÿ���� 1�θ� �̷���� ����(2���� �迭)���� ���� ������ ������ �� ���� ���� ����������, ���� Ʈ�������� �̸� �����Ͽ� ������ ǥ���� �� �ִ�.

�־��� ������ ��� 0���θ� �Ǿ� ������ ���� ����� "0"�� �ǰ�, ��� 1�θ� �Ǿ� ������ ���� ����� "1"�� �ȴ�. ���� 0�� 1�� ���� ������ ��ü�� �� ���� ��Ÿ������ ���ϰ�, ���� ��, ������ ��, ���� �Ʒ�, ������ �Ʒ�, �̷��� 4���� �������� ������ �����ϰ� �Ǹ�, �� 4���� ������ ������ ����� ���ʴ�� ��ȣ �ȿ� ��� ǥ���Ѵ�

	check(sx + N / 2, sy, N / 2);
	check(sx, sy + N / 2, N / 2);
�� �κ� ��踦 �ݴ�� ȣ���ؼ� ���� �̻��ϰ� �����µ� �� �׷� ���� ��ã�Ҵ��� �ð� �ɸ� ����

- char �迭 ���� �ʰ� string �迭���� Ǯ��
- isSame �����ؼ� �����ʰ� ���ǹ� �ȿ��� ��͸� �����ص� �ȴ�.
*/
#include <iostream>
using namespace std;

char map[65][65];

void check(int sx, int sy, int N) {

	char n = map[sy][sx];
	bool isSame = true;
	for (int i = sy; i < sy + N; i++)
	{
		for (int j = sx; j < sx + N; j++)
		{
			if (map[i][j] != n)
			{
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}
	if (isSame)
	{
		cout << n;
		return;
	}
	cout << "(";
	check(sx, sy, N / 2);
	check(sx + N / 2, sy, N / 2);
	check(sx, sy + N / 2, N / 2);
	check(sx + N / 2, sy + N / 2, N / 2);
	cout << ")";
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = s[j];
		}
	}
	check(0, 0, N);
	return 0;
}