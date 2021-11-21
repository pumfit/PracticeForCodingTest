/*
서로 다른 자연수의 합

양의 정수 N (1 ≤ N ≤ 2000)을 서로 다른 자연수의 합으로
나타내는 방법은 여러 가지가 있다.

예를 들어, N = 5인 경우 N = 5 = 2 + 3 = 1 + 4로 총 3가지 방법이 있다. 
1 + 1 + 3에서 1은 여러 번 등장하기 때문에 세지 않고, 2 + 3과 3 + 2는 순서만 바뀐 것이기 때문에 같은 것으로 센다.

또, N = 6인 경우에는 N = 6 = 1 + 5 = 1 + 2 + 3 = 2 + 4로 총 4가지 방법이 있다.

N이 주어졌을 때, 서로 다른 자연수의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

각 테스트 케이스마다 N을 서로 다른 자연수의 합으로 나타내는 방법의 수 100999로 나눈 나머지를 출력한다.
*/
#include<iostream>
using namespace std;

int dp[2001] = { 0, };

int main()
{
	int T;
	cin >> T;
	dp[1] = dp[2] = 1; dp[3] = 2;
	for (int i = 4; i < 2001; i++)
		dp[i] = dp[i-2]% 100999 + dp[i-3]% 100999;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << dp[n]<<endl;
	}
}