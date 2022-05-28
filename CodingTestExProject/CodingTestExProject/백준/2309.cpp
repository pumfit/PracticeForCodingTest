/*
2309 �ϰ� ������

�������� ���� ������� ���� ��� �̷��� ���� Ǯ�̸� �����ϴ� ���� �ʹ� �ű��ϴ�.
BF���� �����ϱ� �������.
BF�� Ǯ��߰ڴ� -> 100�̵Ǵ� ��ü�� ���ϱ⿣ �ݺ����� �ʹ� ���� �ʿ�
->  ��ü ���� ���� �� ������ ���� �����ؼ� ���� �ǰڴ�.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[9] = { 0, };
int visited[9] = { 0, };
int sum = 0;

int main() {
	for (int i = 0; i < 9; i++)
	{
		int N;
		cin >> N;
		arr[i] = N;
		sum += N;
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j)
						continue;
					cout << arr[k] << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}