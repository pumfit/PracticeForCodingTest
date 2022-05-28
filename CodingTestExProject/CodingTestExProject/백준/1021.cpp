/*
1021 ȸ���ϴ� ť

�����̴� N���� ���Ҹ� �����ϰ� �ִ� ����� ��ȯ ť�� ������ �ִ�. �����̴� �� ť���� �� ���� ���Ҹ� �̾Ƴ����� �Ѵ�.

�����̴� �� ť���� ������ ���� 3���� ������ ������ �� �ִ�.

ù ��° ���Ҹ� �̾Ƴ���. �� ������ �����ϸ�, ���� ť�� ���Ұ� a1, ..., ak�̾��� ���� a2, ..., ak�� ���� �ȴ�.
�������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� a2, ..., ak, a1�� �ȴ�.
���������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� ak, a1, ..., ak-1�� �ȴ�.
ť�� ó���� ���ԵǾ� �ִ� �� N�� �־�����. �׸��� �����̰� �̾Ƴ����� �ϴ� ������ ��ġ�� �־�����. (�� ��ġ�� ���� ó�� ť������ ��ġ�̴�.) �̶�, �� ���Ҹ� �־��� ������� �̾Ƴ��µ� ��� 2��, 3�� ������ �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

https://www.acmicpc.net/problem/1021

���� ����Ͽ� �������� �־��� ��� �����ϰ� ���� �� ���� ��츦 ���ϴ� ������� �����ߴ�.
�ش� Ǯ�� ���� �ε����� ���� �� ���� ��ġ���� ���̸� ���� Ǫ�� ��ĵ� �ִ�.
*/
#include <iostream>
#include <deque>
using namespace std;

int main() {
	deque<int> d;
	int arr[51] = { 0, };
	int answer = 0;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		d.push_back(i + 1);
	for (int i = 0; i < M; i++)
		cin >> arr[i];
	for (int i = 0; i < M; i++)
	{
		int cntA = 0, cntB = 0;
		deque<int> tempA = d;
		deque<int> tempB = d;
		while (arr[i] != tempA.front())
		{
			int x = tempA.front();
			tempA.pop_front();
			tempA.push_back(x);
			cntA++;
		}
		while (arr[i] != tempB.front())
		{
			int x = tempB.back();
			tempB.pop_back();
			tempB.push_front(x);
			cntB++;
		}
		if (cntA > cntB) {
			d = tempB;
			answer += cntB;
		}
		else {
			d = tempA;
			answer += cntA;
		}
		d.pop_front();
	}
	cout << answer;
	return 0;
}