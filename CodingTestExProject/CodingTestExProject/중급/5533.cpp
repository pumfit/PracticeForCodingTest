/*
5533 ����ũ

ī��Ʈ�� �÷��� ���ϴ¹������ ����Ǯ�̸� �����ߴµ� ��üŽ���� �����ϴٺ��� �ð�������
8ms�� �ɷȴ�.
			  if (a[i][k] == a[j][k] && i != j)
				{
					cnt = 1;
					break;
				}
�� ���� �޾ƿ� �������迭�� ���ϴ� for���� �ٷ� ����ϴ� ���� �� ���� Ǯ�� �� �� ����.
*/
#include<iostream>
using namespace std;

int main()
{
	int N;
	int arr[202][3];
	int score[202] = {0,};
	cin >> N;

	for (int i=0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int n;
			cin >> n;
			arr[i][j] = n;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		int num[101] = { 0, };
		for (int j = 0; j < N; j++)
		{
			num[arr[j][i]]++;
		}
		for (int j = 0; j < N; j++)
		{
			if (num[arr[j][i]] == 1)
				score[j] += arr[j][i];
		}
	}
	for (int j = 0; j < N; j++)
	{
		cout << score[j] << endl;
	}
}