/*
1522 ���ڿ� ��ȯ

https://www.acmicpc.net/problem/1522

��� ��ȯ Ƚ���� ���� �� �ִ��� ��� ���� �� ���� 
��ü Ž���� �ʼ����̰ڴ� �����ϰ� ������ �����غ��� ��ü a�� ������ŭ �񱳸� �ϰ� b�� ��쿣 ��ü ȸ���� ī��Ʈ���ָ� �ȴ�.

+) �����̵� ������� 2�� for���� ���� �� �ִ� ���� 
������ ���� cntA��ŭ ���ϸ� �ǹǷ� i ~ i + cntA-1  ���� ���� ��� �ٽ� ���ϴ� ���̾ƴ϶� �糡 ���� üũ�ϸ�Ǵ� ����̴�.

�����̵� ������
https://wikidocs.net/154706
*/
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int cntA = 0, cntB = 0;
	int size = s.size();

	// ���ڿ��� ���Ե� ��ü a�� ������ b�� ������ ���Ѵ�.
	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'a')
		{
			cntA++;
		}
	}
	for (int i = 0; i < cntA; i++)
	{
		if (s[i] == 'b')
		{
			cntB++;
		}
	}
	// �ʱⰪ�� b�� ������ �ʱ�ȭ�Ѵ�.
	int MinCnt = cntB;

	// �迭�� ��ȸ�ϸ鼭 
	for (int i = 1; i < size; i++)
	{
		if (s[i - 1] == 'b')
		{
			cntB--;
		}
		if (s[(i + cntA - 1) % size] == 'b')
		{
			cntB++;
		}
		MinCnt = min(cntB, MinCnt);
	}
	cout << MinCnt;
	return 0;
}