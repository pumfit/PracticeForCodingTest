/*
10807 개수 세기

https://www.acmicpc.net/problem/10807

범위가 음수 인 경우가 있음에  유의 해야하는 문제 배열의 인덱스에 음수가 들어가면 런타임에러가 발생한다.
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