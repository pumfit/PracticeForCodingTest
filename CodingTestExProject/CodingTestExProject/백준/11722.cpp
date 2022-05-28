/*
11722 가장 긴 감소하는 부분 수열

수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 
가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

오랫만에 dp문제 복습하면서 이전에 실수했던 부분인 idx 0인부분 초기화도 잊지 않고 진행했다.
*/
#include <iostream>
#include <algorithm>
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