/*
2302 극장 좌석
https://www.acmicpc.net/problem/2302

이전 문제 테케 넣어놓고 왜 안되는 거지...이러고 있었음... 
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N,M;
	int dp[41] = {0,};
	dp[0] = 1; dp[1] = 1;
	cin>>N>>M;
    //1. 좌석 연석마다 경우의 수 dp로 구하기 
	for(int i = 2;i<=N;i++)
	{
		dp[i] = dp[i-2]+dp[i-1];
	}
    //2. 좌석 간격 마다 경우의 수 구하기
	vector<int> v;
	int prev = 0; int cur = 0;
	for(int i = 0;i<M;i++)
	{
		cin>>cur;
		v.push_back(dp[cur-prev-1]);
		prev = cur;
	}
	if(prev!=0)
		v.push_back(dp[N-prev]);
	else
		v.push_back(dp[N]);
    //3. 모든 경우의 수를 곱하여 가능한 배치 수 구하기
	int answer = 1;
	for(int i = 0;i<v.size();i++)
	{
		answer *= v[i];
	}
	cout<<answer;
	return 0;
}