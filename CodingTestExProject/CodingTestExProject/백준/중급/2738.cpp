/*
2738�� ��ĵ���

��� ������ �迭
1.���� �ΰ��� �迭�� �ʱ�ȭ�ϰ�
�ش�迭�� �Էµ� ���� �ߵ����� Ȯ��
2.�´ٸ� ���� ���� �ش� ���ǿ� �°� ����ϱ�

���� ��� �ð� : 4ms ���� : 560B �� ���Դ�.
+) �ð� ���� ����� ��� �������� �� �����غ���
*/

#include<iostream>

using namespace std;

int main()
{
	int A[100][100] = { 0,{0,} }, B[100][100] = { 0,{0,} };
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int c;
			cin >> c;
			A[j][i] = c;
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int c;
			cin >> c;
			B[j][i] = c;
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << A[j][i]+B[j][i];
			if (j != b - 1)
				cout << " ";
		}
		if(i!=a-1)
			cout << "\n";
	}
}