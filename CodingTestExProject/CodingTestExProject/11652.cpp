/*
11652 ī��

�رԴ� ���� ī�� N���� ������ �ִ�. ���� ī�忡�� ������ �ϳ� �����ִµ�, �����ִ� ���� -262���� ũ�ų� ����, 262���� �۰ų� ����.

�ر԰� ������ �ִ� ī�尡 �־����� ��, ���� ���� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ����, ���� ���� ������ �ִ� ������ ���� �������, ���� ���� ����Ѵ�.

https://www.acmicpc.net/problem/11652

������ �ٷ� ��������� �¾Ҵµ� 40�� ������ ���� ���� ó���� ������ �Ŷ� num�� ������ long long���� �������� �ʾҴ� �� ������
���� 10���� ���� �� Ʋ�� ����
�ش� ������ map���ε� Ǯ �� ���� �� ���Ƽ� ���� Ǯ�� �߰��� �غ��� ���� �� ����.


*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
long long arr[100005] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int cnt = 0, maxCnt = 0;
	long long num = -(111 << 62) - 1;
	for (int i = 0; i < N; i++)
	{
		if (i == 0 || arr[i - 1] == arr[i])
			cnt++;
		else
		{
			if (cnt > maxCnt)
			{
				maxCnt = cnt;
				num = arr[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > maxCnt)
		num = arr[N - 1];
	cout << num;
	return 0;
}