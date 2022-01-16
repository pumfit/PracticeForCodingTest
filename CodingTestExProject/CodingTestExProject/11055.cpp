/*
11055 가장 큰 증가 부분 수열

수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

기존의 가장 긴 증가 부분 수열에서 변형하는 방식으로 문제를 풀어나갔다.
이때 이문제를 풀며 두번 틀렸는데 그 이유는 dp[0] 초기화와 j 범위 초기화였다.
dp[0] 를 1로 초기화 해두어서 arr[0]으로 바꾸었더니 99퍼에서 틀렸고
테케를 내림차순으로 돌려보니 dp[0]이 아닌 dp[1]이최대로 나오는 것을 확인 할 수 있었다.
j = i로 바꾸고 최대값을 찾게 하였더니 통과했다.

+)
초기값 초기화 주의하기
테케 여러개 생각해보고 돌려보기
*/
#include <iostream>
using namespace std;

int arr[1001];
int dp[1001] = { 0, };
int N;

int main() {
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	dp[0] = arr[0];
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (arr[i] < arr[j])
			{
				dp[j] = max(dp[i] + arr[j], dp[j]);
			}
			else
			{
				dp[j] = max(arr[j], dp[j]);
			}
			ans = max(ans, dp[j]);
		}
	}
	cout << ans;
	return 0;
}