/*
11053 가장 긴 증가하는 부분 수열

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 
부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

가장 긴 감소하는 부분 수열 복습차 문제풀이를 진행했다.
처음에 max값을 이중 for문 가장안에 해서 비효율적이었는데 빼냈다.

*/
#include <iostream>
using namespace std;

int arr[1001];
int dp[1001];
int answer;
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	dp[0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[j] = max(dp[i] + 1, dp[j]);
			}
			else
			{
				dp[j] = max(1, dp[j]);
			}
		}

		answer = max(answer, dp[i]);
	}
	cout << answer;
	return 0;
}