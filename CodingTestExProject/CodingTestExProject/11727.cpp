/*
11727 2xN Ÿ�ϸ� 2

2��n ���簢���� 1��2, 2��1�� 2��2 Ÿ�Ϸ� 
ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1�϶� 1
2�϶� 3
3�϶� 5 1*2 + 3
4�϶� 11 2*3 + 5

���� ������ 2x2�� �߰��Ǹ鼭 n-2�� ��찡 2��� �����ϴ� ���� �� �� �ִ�.
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