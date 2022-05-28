/*
18870 ��ǥ����

������ ���� N���� ��ǥ X1, X2, ..., XN�� �ִ�. �� ��ǥ�� ��ǥ ������ �����Ϸ��� �Ѵ�.

Xi�� ��ǥ ������ ��� X'i�� ���� Xi > Xj�� �����ϴ� ���� �ٸ� ��ǥ�� ������ ���ƾ� �Ѵ�.

X1, X2, ..., XN�� ��ǥ ������ ������ ��� X'1, X'2, ..., X'N�� ����غ���.

https://www.acmicpc.net/problem/18870
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N = 0;
	int arr[1000001] = { 0, };
	int arr_sort[1000001] = { 0, };
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	copy(arr, arr + N, arr_sort);
	sort(arr_sort, arr_sort + N);
	v.push_back(arr_sort[0]);
	for (int i = 1; i < N; i++)
	{
		if (arr_sort[i - 1] != arr_sort[i])
			v.push_back(arr_sort[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
		cout << lower_bound(v.begin(), v.end(), arr[i]) - v.begin() << " ";
	return 0;
}