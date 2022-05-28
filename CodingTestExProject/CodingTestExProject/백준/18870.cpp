/*
18870 좌표압축

수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

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