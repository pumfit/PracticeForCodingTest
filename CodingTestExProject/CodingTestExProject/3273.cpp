/*
3273 �� ���� ��

arr�ȿ� �ִ� �迭��ũ�⸦ ����� �����������ʾ� �� �����̳� Ʋ�� ����..
https://www.acmicpc.net/problem/3273
*/
#include <iostream>
using namespace std;

int arr[2000001] = { 0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N, X, cnt = 0;
	int n;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		arr[n]++;
	}
	cin >> X;
	int tempX = X % 2 == 0 ? X / 2 : X / 2 + 1;
	for (int i = 1; i < tempX; i++)
	{
		if (arr[i] == 1 && arr[X - i] == 1)
			cnt++;
	}
	cout << cnt;
	return 0;
}