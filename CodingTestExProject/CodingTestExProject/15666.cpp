/*
15666 N과 M (12)

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다. 고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

이번 문제의 주요 포인트는 1,7 과 7,1을 걸러야하므로 i = 0에서부터 시작하는 게 아닌 이전 인덱스값부터 시작해야한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[10] = { 0, };
int arr[10] = { 0, };
void bf(int n, int idx) {
	if (n == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int i = idx; i < N; i++)
	{
		if (prev != num[i])
		{
			prev = num[i];
			arr[n] = num[i];
			bf(n + 1, i);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	bf(0, 0);
	return 0;
}