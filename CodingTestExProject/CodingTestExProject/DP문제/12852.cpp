/*
12852 1로 만들기 2
https://www.acmicpc.net/problem/12852

dp 복습 겸 선택한 문제 
두번째 줄의 출력은 dp 하면서 prev 를 따로 저장하거나 기존 로직대로 출력하되 최소 연산이도록 확인하는 방법이 있다.
두번째 방식으로 풀이를 진행했다.

+ ) dp 초기화할때 MAX 까지 모두 초기화하지 않고 N까지만 초기화하기
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1000001

int main() {
	int N;
	cin>>N;
	int dp[MAX]= {0,};
	fill(dp,dp+N+1,MAX);
	dp[1] = 0; 
	for(int i = 1;i<=N;i++)
	{
		if(i*2 <= N && dp[i*2] > dp[i]+1)
			dp[i*2] = min(dp[i*2],dp[i]+1);
		if(i*3 <= N && dp[i*3] > dp[i]+1)
			dp[i*3] = min(dp[i*3],dp[i]+1);
		if(i+1 <= N && dp[i+1] > dp[i]+1)
			dp[i+1] = min(dp[i+1],dp[i]+1);
	}
	cout<<dp[N]<<'\n';
	int n = N; int cnt = dp[N];
	while(n!=1)
	{
		cout<<n<<" ";
		if(n%2==0 && dp[n/2] == cnt - 1)
		{
			n /= 2;
		}
		else if(n%3==0 && dp[n/3]== cnt -1)
		{
			n /= 3;
		}
		else
		{
			n -= 1;
		}

		cnt -= 1;
			
	}
	cout<<1;
	return 0;
}