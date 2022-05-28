/*
15988 1,2,3 ¥ı«œ±‚ 3
*/
#include <iostream>
using namespace std;

long memo[1000001];

long dp(int n)
{
	if (memo[n] != 0)
		return memo[n];
	else
		return memo[n] = (dp(n - 1) + dp(n - 2) + dp(n - 3)) % 1000000009;
}

int main() {
	int T;
	cin >> T;
	memo[1] = 1; memo[2] = 2; memo[3] = 4;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << dp(N) << endl;
	}
	return 0;
}