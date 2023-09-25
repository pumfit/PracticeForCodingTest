/*
1915 가장 큰 정사각형
https://www.acmicpc.net/problem/1915

이전에 동일한 문제 풀었었는데 이번에도 2번 틀리고 맞았다. 접근 방식은 알고있어서 빨리 풀긴 했지만 단일 테케 통과했다고 제출하지 않고
다른 부분 확인해보고 내는 습관 들이는 게 좋을 것 같다.

- 오답 테케
입력이 1 1 1 인 경우 0이 나옴
맨 처음 maxSide = 0으로 지정하고 크기가 1인 경우 아래 조건에서 판단을 못해서 가장 큰 정사각형 크기가 0으로 출력되었음

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N,M;
	int dp[1001][1001];
	cin>>N>>M;
	int maxSide = 0;
	for(int y = 0;y<N;y++)
	{
		string s;
		cin>>s;
		for(int x = 0;x<M;x++)
		{
			dp[x][y] = s[x] - '0';
			maxSide = max(dp[x][y],maxSide);
		}
	}
	for(int y = 0;y<N;y++)
	{
		for(int x = 0;x<M;x++)
		{
			if(dp[x][y]==0)
				continue;
			
			if(x-1<0||y-1<0)
				continue;
				
			if(dp[x-1][y]==0 || dp[x][y-1]==0 || dp[x-1][y-1]==0 )
				continue;
				
			dp[x][y] = max(dp[x][y], min(min(dp[x-1][y],dp[x][y-1]),dp[x-1][y-1])+1);

			maxSide = max(dp[x][y],maxSide);
		}
	}

	cout<<maxSide * maxSide;
	return 0;
}
