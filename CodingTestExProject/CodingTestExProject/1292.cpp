/*
1292�� ���� Ǫ�� ����
 
 ���1.
 1000����  �迭����� �޾ƿ� ������ŭ ���Ѵ�.

vector subscript out of range ->1000
idx ���� �������� for�� �迭�� ���Ǵ� �������� ��ȭ �����ϱ�

*/

#include<iostream>
using namespace std;

int main()
{
	int arr[1000];
	int sum = 0, idx = 0, num = 1;
	int a, b;

	cin >> a;
	cin >> b;

	for (int i = 0; idx < 1000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[idx++] = num;
			if (idx == 1000)
				break;
		}
		num++;
	}

	for (int k = a-1; k < b; k++) 
	{
		sum += arr[k];
	}
	cout << sum;
}