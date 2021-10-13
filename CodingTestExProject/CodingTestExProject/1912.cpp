#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001] = { 0, };
int dp[1000001] = { 0, };

int main() {
	int T;
	cin >> T;

	cin >> dp[0];
	int m = dp[0];

	for (int i = 1; i < T; i++)
	{
		int N;
		cin >> N;
		arr[i] = N;
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);//i까지 연속합의 최대값
		m = max(m, dp[i]);
	}
	cout << m;
	return 0;
}