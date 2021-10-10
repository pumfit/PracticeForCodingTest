/*
11726 2xn 타일링

2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

dp가 뭔지...bfs 요즘 풀다가 골드라인에서 막히고 이거 dfs로 풀면 되는거 아닌가..?했는데
dp로 풀이하는 것이라길래 일단 dp 낮은 문제들을 풀어보며 유형을 파악하자고 생각하고
몇몇 dp 글과 문제집을 찾아봤다.

이문제는 n이 5일때까지 구해본 후
점화식이 f(n) = f(n-2)+f(n-1) 임을 알 수 있었다. (구하는데 꽤 걸렸다..)
처음에 memo[n] = (dp(n - 1) + dp(n - 2))를 dp에서 리턴하고 메인에서 10007을 나눴더니 틀렸다.
memo에 저장할 때 출력값을 저장하는 것이므로 해당 연산을 리턴하는 줄에서 해줘야한다.
*/

#include<iostream>
using namespace std;

int memo[1001];

int dp(int n)
{
	if (memo[n] != 0)
		return memo[n];
	if (memo[n] == 0)
		return memo[n] = (dp(n - 1) + dp(n - 2)) % 10007;
}

int main()
{
	int N;
	cin >> N;
	memo[0] = -1; memo[1] = 1; memo[2] = 2;
	cout << dp(N);
}