/*
2164 ī��2

https://www.acmicpc.net/problem/2164
N���� ī�尡 �ִ�. ������ ī��� ���ʷ� 1���� N������ ��ȣ�� �پ� ������, 1�� ī�尡 ���� ����, N�� ī�尡 ���� �Ʒ��� ���·� ������� ī�尡 ���� �ִ�.
���� ������ ���� ������ ī�尡 �� �� ���� ������ �ݺ��ϰ� �ȴ�. �켱, ���� ���� �ִ� ī�带 �ٴڿ� ������. �� ����, ���� ���� �ִ� ī�带 ���� �Ʒ��� �ִ� ī�� ������ �ű��.

ť ������ �̿��Ͽ� Ǯ�� �Ǵ� ����
*/
#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);
	while (q.size() > 1) {
		q.pop();
		int tmp = q.front();
		q.push(tmp);
		q.pop();
	}
	cout << q.front();
}