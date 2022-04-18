/*
1920 수 찾기

N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

처음에 문제 잘못읽고 정수 범위가 100001까지인줄 알았다가 out of index 받은 문제이다.
이분탐색 algorithm 헤더에  있는 함수로 사용해서 풀 수 있는 문제지만 이분탐색 구현은 중요하므로 이후에 다시 구현해서 풀어보기
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