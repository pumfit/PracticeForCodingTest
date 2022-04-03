/*
9037 The candy war

https://www.acmicpc.net/problem/9037

동시에 가 포인트인 문제인데 동시에 넘겨주지않고 넘겨주면서 홀수인지 체크해서 오래걸렸던 문제
문제를 잘 읽자... 
동시에 더해주기 위해 add 배열을 추가해 더해줄 값들을 저장했다.

다른 풀이를 보면 모든 값이 같은지 아닌지 판단할때 인덱스 1~N과 0을 비교하는 방식을 많이 쓰는 것 같았다.
*/

#include <iostream>
using namespace std;
int T,N;
bool isSame;
int arr[11]={0,};
int add[11]={0,};
void CheckIsSame()
{
	for(int j=0;j<N-1;j++)
	{
		if(arr[j]==arr[j+1])
		{
			continue;
		}else
		{
			isSame = false;
			break;
		}
	}
}
int main() {
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		for(int j=0;j<N;j++)
		{
			cin>>arr[j];
		}
		int cnt = 0;
		for(int j=0;j<N;j++)
		{
			if(arr[j]%2==1)
				arr[j]++;
		}
		isSame = true;
		CheckIsSame();
		while(!isSame)
		{
			isSame = true;
			for(int j=0;j<N;j++)
			{
				arr[j]/=2;
				add[(j+1)%N] = arr[j];
			}
			for(int j=0;j<N;j++)
			{
				arr[j] += add[j];
				if(arr[j]%2==1)
					arr[j]++;
			}
		CheckSame();
		cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}