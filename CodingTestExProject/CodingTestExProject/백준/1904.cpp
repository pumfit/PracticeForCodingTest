#include <iostream>
using namespace std;

int main() {
	int N;
	cin>>N;
	long long dp[1000001] = {0,};
	dp[1] = 1; dp[2] = 2; dp[3] = 3;
	for(int i = 3;i<=N;i++)
	{
		dp[i] = (dp[i-1]+dp[i-2])%15746;
	}
	
	cout<<dp[N];
	return 0;
}