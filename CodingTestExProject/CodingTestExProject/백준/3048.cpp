/*
3048 ����

insert ��� �����..? �ߴ� ���� insert(idx,char) �������� ��ٰ� ã�ƺ��� ���ƴ�.
���� �ᰡ�鼭 Ǯ��Ҵµ� B�� ���������� �ΰ� A�� �����̴� ������� �ε����� ����� Ǯ����.
A�� ù ���ڴ� T��ŭ �����δ�. �� ���ķδ� 1�� �������鼭 �����̰� �ش簪�� �ε��� ������ �Ѿ�� �ʵ��� ó�����ش�.
+
�������� ª�� Ǯ�����ߴµ� ���ڵ� 10���� ���� �ű��ߴ� ����
ª���� ��� ���� Ǯ���� ���� �ƴ����� �����ߴ� �ٸ�Ǯ�̺��� ������ Ǯ���� ���� Ȯ���� ����
*/
#include <iostream>
using namespace std;

int main() {
	int A, B, T, idx;
	string a, b;
	cin >> A >> B >> a >> b >> T;
	string answer = b;
	for (int i = 0; i < A; i++)
	{
		if (T - i < 0)
			idx = 0;
		else if (T - i > B)
			idx = B;
		else
			idx = T - i;
		answer.insert(idx, 1, a[i]);
	}
	cout << answer;
	return 0;
}