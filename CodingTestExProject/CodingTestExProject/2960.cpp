/*
2960 �����佺�׳׽��� ü �ڡڡ�

N���� �۰ų� ���� ��� �Ҽ��� ã�� �˰���
���� K��°�� ����� ���� �������� ã�� ����

210816 �絵��
�־��� ������ ������ �°� �����ϰ� ���� k��°�� ���� ã�Ƴ�����.
while���� �ι����ٺ��� ù �ݺ����� break������ �� �־ ���� �����µ� ������ ���⵵�ߴ�.
�ٸ� Ǯ�̸� ���캸�� ��ø for������ ����ϰ� Ǫ�� Ǯ�̵鵵 �־���. �ٸ� Ǯ�̵鵵 ���� ���
�ܼ��ϰ� Ǯ �� �ִ��� ���캸�ƾ߰ڴ�.
*/

#include <iostream>
using namespace std;

int main()
{
	int N,K;
	int idx = 0;
	bool arr[1001] = { 0, };

	cin >> N >> K;

	int p = 2;
	while (true)
	{
		int temp = p;
		while (temp <= N)
		{
			if (!arr[temp])
			{
				arr[temp] = true;//����
				idx++;
				if (idx == K)
				{
					cout << temp;
					break;
				}
			}
			temp += p;
		}
		while (true)
		{
			p++;
			if (!arr[p])
				break;
		}
		if (idx == K)
		{
			break;
		}
	}
}