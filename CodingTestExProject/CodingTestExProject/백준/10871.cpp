/*
10871 X보다 작은 수

https://www.acmicpc.net/problem/10871
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, X;
	int arr[10001];
	cin >> N >> X;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < X)
			cout << arr[i] << " ";
	}
	return 0;
}