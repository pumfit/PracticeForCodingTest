/*
2495 ���ӱ���

�ڸ����� �������ְ� ���ڸ����� 0~9������ ���� Ȱ���ؼ� ������ Ǯ����� �ȴ�.
���ӵǴ� �� ���� ���������� �Ǵ��ϰ� ī��Ʈ�� �ø��� �Ǳ� ������ ������ ��쿣 ī��Ʈ�� �ø���
�ƴ� ���� max���� �Ǵ��ϵ��� �ߴ�.

�׸��� ù ���⿡�� Ʋ�Ⱦ��µ� �ݺ����� ������ ������ max�� Ȯ���� �ѹ� �� ������Ѵ�.
39-42line�� �߰����־ ����Ͽ���.
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		int num[10] = { 0, };
		int max = 0,m=0;

		string N;
		cin >> N;
		for (int j = 0; j < N.length()-1; j++)
		{
			if (N[j] == N[j + 1])
			{
				m++;
			}
			else
			{
				if (m + 1 > max)
				{
					max = m + 1;
				}
				m = 0;
			}
		}
		if (m + 1 > max)
		{
			max = m + 1;
		}

		cout << max <<endl;
	}
}