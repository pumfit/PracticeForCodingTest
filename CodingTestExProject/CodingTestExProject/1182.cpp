/*
1182 부분수열의 합
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

https://www.acmicpc.net/problem/1182

BT 문제 
N = 20 이라 시간적으로 여유있는 편
부분 수열이라 시작하는 지점을 모두 한번씩 지나 가고
합이 S인 경우 return 하지 않고 이후에도 답이 될 수 있기 때문에 이후에도 전체를 탐색하도록 했다. 
*/
#include <iostream>
using namespace std;

int N, S;
int arr[21] = { 0, };
int cnt = 0;

void bt(int n, int sum) {

	sum += arr[n];
	if (sum == S)
	{
		cnt++;
	}
	for (int i = n + 1; i < N; i++)
	{
		bt(i, sum);
	}
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
		bt(i, 0);
	cout << cnt;
	return 0;
}