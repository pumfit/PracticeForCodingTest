/*
11727 2xN 타일링 2

2×n 직사각형을 1×2, 2×1과 2×2 타일로 
채우는 방법의 수를 구하는 프로그램을 작성하시오.

1일때 1
2일때 3
3일때 5 1*2 + 3
4일때 11 2*3 + 5

이전 문제에 2x2가 추가되면서 n-2의 경우가 2배로 증가하는 것을 알 수 있다.
*/
#include<iostream>
#include<algorithm>
using namespace std;

int memo[1000001];

int dp(int n)
{
	if (memo[n] != 0)
		return memo[n];
	if (memo[n] == 0)
		return memo[n] = ( dp(n - 1) + 2 * dp(n - 2) ) % 10007;
}

int main()
{
	int N;
	cin >> N;
	memo[1] = 1; memo[2] = 3;
	cout << dp(N);
}