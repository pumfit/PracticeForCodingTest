/*
21756 ���찳

https://www.acmicpc.net/problem/21756

���� �̸��� ���찳���� Ǯ�̴� �ݴ�� Ȧ���� ��츸 ��Ƽ� Ǯ����. N�� 100 �̶� ����� �����ϴٰ� �Ǵ��߰�
�ٸ� Ǯ�̴� �������� �ʾƼ� ���Ͱ��� Ǯ���µ�
ª�� Ǯ�̷δ� ���������� (1 << (int) (log(n) / log(2))); �� ���� Ǯ �� �ִٴ� ���� ������
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++)
		v.push_back(i + 1);
	while (1 != v.size())
	{
		vector<int> v2;
		for (int i = 0; i < v.size(); i++)
		{
			if (i % 2 == 1)
				v2.push_back(v[i]);
		}
		v = v2;
	}
	cout << v[0];
	return 0;
}