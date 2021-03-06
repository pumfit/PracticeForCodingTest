/*
11728 배열 합치기

정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

https://www.acmicpc.net/problem/11728

시간초과나지 않게 주의하고 각 배열의 인덱스가 마지막인덱스인 경우 다른 배열이 들어가도록 로직을 구성하면 된다.

정렬1 강의 문제
https://www.youtube.com/watch?v=59fZkZO0Bo4&ab_channel=BaaarkingDog

*/
#include <iostream>
using namespace std;

int n, m;
int a[1000005], b[1000005], c[2000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int idxA = 0; int idxB = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (idxB == m)//배열 B를 모두 C에 넣은 경우 
			c[i] = a[idxA++];
		else if (idxA == n)//배열 A를 모두 C에 넣은 경우 
			c[i] = b[idxB++];
		else if (a[idxA] <= b[idxB])//배열 A,B를 비교해 더 작은 수를 넣음
			c[i] = a[idxA++];
		else
			c[i] = b[idxB++];
	}
	for (int i = 0; i < n + m; i++)
		cout << c[i] << " ";
	return 0;
}