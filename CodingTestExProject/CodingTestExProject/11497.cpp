/*
11497 �볪�� �ǳʶٱ�

ó���� ������ ���� i�� i-2�� ���谡 �ִٴ� ���� �˰�
���� �� ���� ū���� ����°�� ū ���� �� ���� �������� ����Ͽ���.
������ ��� �¾����� ä������� Ʋ�ȴ�.

i,i-2�� �ش�Ǵ� ������ ���� ū ������ ã�Ƴ��� �׸��� �����̴�.
���� ������ �ݺ����� ���� ��ü Ž���� �����ϸ鼭 �����ظ� ã���� �ȴ�.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N;
int arr[10001];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int answer = 0;
		for (int j = 0; j < N; j++)
			cin >> arr[j];
		sort(arr, arr + N);
		for (int j = 0; j < N - 2; j++)
		{
			answer = max(answer, arr[j + 2] - arr[j]);
		}
		cout << answer << endl;
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}