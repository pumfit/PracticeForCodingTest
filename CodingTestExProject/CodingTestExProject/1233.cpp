/*
1233 �ֻ���

���� ������ Ǯ��
�迭�� �����ؼ� ��� ����� ���� ���� ��ü �� �迭���� �ִ밪�� ���Ѵ�.
�迭�� �ִ밡 �������־� �ð� ������ ���� ���� �� ���ٰ� �����ߴ�.

Ǯ�鼭 �ٸ� Ǯ�̰� ���� ������? ������ ������� ���� ã�ƺ��� ���� Ž���� �´� �������.
������ Ǯ�̴�� �غ��� ���� ������ �ٸ� Ǯ�̸� �������� 

+) �̻��� ������ ���� Ʋ�ȴ�����
max���� �ε������� �Ǿ���ؼ� arr[max]��  arr[i]�� ���ؾ��ϴµ�
max�� arr[i]�� ���߰� �� ��� �׽�Ʈ ���̽� ���� ���ͼ� �׳� �����ع��Ⱦ���.
�񱳴���� ��Ȯ�� �� ��!!
*/
#include <iostream>
using namespace std;

int main()
{
	int s1[21] = {0,}, s2[21] = { 0, }, s3[41] = { 0, };
	int arr[81] = {0,};
	int max = 0;
	int N, M, L;

	cin >> N >> M >> L;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int k = 1; k <= L; k++)
			{
				arr[i + j + k]++;
			}
		}
	}

	for (int i = 3; i < 81; i++)
	{
		if(arr[max]<arr[i])
			max = i;
	}

	cout << max;
}