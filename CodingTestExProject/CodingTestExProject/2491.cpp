/*
2491 수열

0에서부터 9까지의 숫자로 이루어진 N개의 숫자가 나열된 수열이 있다. 그 수열 안에서 연속해서 커지거나(같은 것 포함), 혹은 연속해서 작아지는(같은 것 포함) 수열 중 가장 길이가 긴 것을 찾아내어 그 길이를 출력하는 프로그램을 작성하라.

예를 들어 수열 1, 2, 2, 4, 4, 5, 7, 7, 2 의 경우에는 1 ≤ 2 ≤ 2 ≤ 4 ≤ 4 ≤ 5 ≤ 7 ≤ 7 이 가장 긴 구간이 되므로 그 길이 8을 출력한다. 
수열 4, 1, 3, 3, 2, 2, 9, 2, 3 의 경우에는 3 ≥ 3 ≥ 2 ≥ 2 가 가장 긴 구간이 되므로 그 길이 4를 출력한다. 
또 1, 5, 3, 6, 4, 7, 1, 3, 2, 9, 5 의 경우에는 
연속해서 커지거나 작아지는 수열의 길이가 3 이상인 경우가 없으므로 2를 출력하여야 한다.

딱 보자마자 DP문제
96퍼에서 한번 틀렸었는데
dp초기화한 후 dp[0]= 1로 변경한 후 100퍼대에서 또 틀렸다.
다른 풀이 참고한경우도 틀려서 이상하다 생각한 순간 m 초기화를 0으로 한것이 보였다.
이렇게 하면 N 1일때 0이 최댓값으로 나와 당연히 틀린다.
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[100001];
int dp[100001];
int N;

int main()
{
	cin >> N;
	int m = 1;
	dp[0] = 1;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] <= arr[i])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
		m = max(m, dp[i]);
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] >= arr[i])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = 1;
		}
		m = max(m, dp[i]);
	}
	cout << m;
}
/*
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[100001];
int dp1 =1,dp2 = 1;
int N;

int main()
{
	int m = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 1; i < N; i++)
	{
		if (arr[i-1] <= arr[i])
		{
			dp1++;
		}
		else
		{
			dp1 = 1;
		}
		if (arr[i - 1] >= arr[i])
		{
			dp2++;
		}
		else
		{
			dp2 = 1;
		}
		m = max(m, max(dp1,dp2));
	}
	cout << m;
}
*/
