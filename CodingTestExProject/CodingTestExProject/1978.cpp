/*
1978 �Ҽ�ã��

�Ҽ��� ���õ� �˰����� "�����佺�׳׽��� ü"�� ���� �˻��غ��� �ش� ������ Ǯ�����.

�ѹ� Ʋ�Ⱦ��� ������ 4�� �Ҽ��� �Ǹ���� �ʾұ� �����ε�
�ش� ����� �� N�� ���� �����ٱ��� �������� �� ���ϴ� �������
j*j < N�̶�� �����ߴµ� N=4�� ��찡 ���Ե����ʾҾ���.

*/
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int ans = T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		if (N == 1)
		{
			ans--;
		}
		else
		{
			for (int j = 2; j*j < N; j++)
			{
				if (N%j == 0)
				{
					ans--;
					break;
				}
			}
		}
	}
	cout << ans;
}