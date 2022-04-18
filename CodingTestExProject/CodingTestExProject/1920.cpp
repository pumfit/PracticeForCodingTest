/*
1920 �� ã��

N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

ù° �ٿ� �ڿ��� N(1 �� N �� 100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. ���� �ٿ��� M(1 �� M �� 100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� ������ ������ -231 ���� ũ�ų� ���� 231���� �۴�.

ó���� ���� �߸��а� ���� ������ 100001�������� �˾Ҵٰ� out of index ���� �����̴�.
�̺�Ž�� algorithm �����  �ִ� �Լ��� ����ؼ� Ǯ �� �ִ� �������� �̺�Ž�� ������ �߿��ϹǷ� ���Ŀ� �ٽ� �����ؼ� Ǯ���
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, n, m;
	int arr[100001] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> m;
		if (binary_search(arr, arr + N, m))
			cout << '1' << '\n';
		else
			cout << '0' << '\n';
	}
	return 0;
}