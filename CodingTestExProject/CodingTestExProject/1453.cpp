/*
1453�� �ǽù�˹�

ù��° ���� ���� ���� :�迭ũ��
������ �迭�� �ε����� 1~100�������� �����Ͽ�
101�� �����ϴ� �޾ƿ� b�� -1�� ���ִ� ������ �ʿ��ϴ�.
*/

#include<iostream>

using namespace std;

int main()
{
	int n = 0, ans = 0;
	int arr[101] = {0,};
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		if (arr[b] > 0)
		{
			ans++;
		}
		arr[b]++;

	}
	cout << ans;
}