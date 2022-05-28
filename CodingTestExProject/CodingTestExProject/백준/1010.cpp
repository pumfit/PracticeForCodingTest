/*

1010 다리놓기

Combination 구현 문제 복습

큰수와 작은수가 고정되어있어 전처리를 하지않아도 괜찮았던 문제이다.

*/
#include <iostream>
using namespace std;

int memo[31][31];

int Combination(int n, int r)
{
	if (memo[n][r] != 0)
		return memo[n][r];
	else
		return memo[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < 31; i++)
	{
		memo[i][1] = i;
		memo[i][i] = 1;
	}
	for (int i = 0; i < T; i++)
	{
		int N, M;
		cin >> N >> M;
		cout << Combination(M, N) << endl;
	}
	return 0;
}