/*
10807 ���� ����

https://www.acmicpc.net/problem/10807

������ ���� �� ��찡 ������  ���� �ؾ��ϴ� ���� �迭�� �ε����� ������ ���� ��Ÿ�ӿ����� �߻��Ѵ�.
*/
#include <iostream>
using namespace std;

int arr[201];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int N, v;
	cin >> N;
	int k;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		arr[k + 100]++;
	}
	cin >> v;
	cout << arr[v + 100];
	return 0;
}