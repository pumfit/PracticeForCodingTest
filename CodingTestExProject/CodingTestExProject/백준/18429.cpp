/*
18429 근손실
https://www.acmicpc.net/problem/18429

가능한 경우의 수 개수를 찾는 백트래킹 문제
선택한 키트인지 확인하기 전에 sum 값이 500을 넘는 지 확인해주면 모든 경우를 확인할 수 있다.

*/
#include <iostream>
using namespace std;

int N,K;
int arr[9] = {0,};
int visited[9] = {0,};
int cnt = 0;

void BT(int depth,int sum)
{
	if(depth==N)
	{
		cnt++;
		return;
	}
	
	for(int i = 0;i<N;i++)
	{
		if(visited[i])
			continue;
		if(sum+arr[i]-K<500)
			continue;
			
		visited[i] = 1;
		BT(depth+1,sum+arr[i]-K);
		visited[i] = 0;
	}
}

int main() {
	cin>>N>>K;
	for(int i = 0; i<N;i++)
	{
		cin>>arr[i];
	}
	BT(0,500);
	cout<<cnt;
	return 0;
}