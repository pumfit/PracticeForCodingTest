/*
1463 1로 만들기

1일때 1
2일때 2로 나누어짐 1
3일때 3으로 나누어짐 1
4일때 2로 나누어짐 2
5일때 -1 하고 4일때 +2 3
6일때 3,2 둘다 나누어짐 둘 중 더 작은 값 2
7일때 3 6인경우 +1
8일때 2인 경우 +1 3
9일때 3인경우 +1 2
10일때 4또는 3 -> 3선택 4
11일때 5
12일때

풀었는데 100퍼에서 갑자기 틀렸습니다 떠서 당황했다.
그 이유는 1을 1로 설정해둬서 였고 0으로 고치고 나선 메모리 제한이 떴다.
top down..? 방식의 문제인건가 질문보며 생각하다가 고치고 1넣어보니
이유를 알게되었다. 1일땐 0이므로 예외처리를 하지않으면 재귀에서 빠져나오지 못한다.
따라서 첫번째 조건문에서 n==1일때 예외처리를 해주었더니 문제를 맞출 수 있었다.

DP 유형 풀어본 지 얼마 안되었는데 재귀에 관해 생각해야할 부분들을 여럿 익혀 갈 수 있었던 것 같다.

*/
#include<iostream>
#include<algorithm>
using namespace std;

int memo[1000001];

int dp(int n)
{
	if (memo[n] != 0 || n == 1)
		return memo[n];
	if (n % 2 == 0 && n % 3 == 0)
		return memo[n] = min(dp(n / 2)+1, dp(n / 3)+1);
	if (n % 2 == 0)
		return memo[n] = min(dp(n / 2) + 1,dp(n-1)+1);
	if (n % 3 == 0)
		return memo[n] = min(dp(n / 3) + 1, dp(n - 1) + 1);
	else
		return memo[n] = dp(n - 1) + 1;
}

int main()
{
	int N;
	cin >> N;
	memo[1] = 0; memo[2] = 1; memo[3] = 1;
	cout << dp(N);
}