/*
2959 �ź���

"���� ū ���簢�� �����"�� 4���� ���� ������ ����� �ź��� ����
�ش� ������ Ǯ�̴� ���ĵ� ���� ���� ���� �ι�°�� ū ���� ���ϸ�ȴ�.
(-> ���� ū �� �谡�� ���� �� <- �ι�°�� ū�� ��ι�°�� ���� ��)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> num(4);

	for (int i = 0; i < 4; i++)
	{
		int N;
		cin >> N;
		num[i] = N;
	}
	sort(num.begin(), num.end());

	cout << num[0] * num[2];
	return 0;
}