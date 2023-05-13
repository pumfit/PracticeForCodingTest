/*
10431 줄세우기

https://www.acmicpc.net/problem/10431 

횟수 계산을 위한 구현문제
실제 변경하면서 풀었지만 다른 답들 확인 해보니 현재 기준으로 이전 순번에 큰 수 가 있다면 증가 시키면된다.
*/

#include <iostream>
using namespace std;

int main() {
	int N;
	cin>>N;
	while(N--)
	{
		int arr[21] = {0,};
		int cnt = 0,cur = 0, temp = 0;
		for(int i = 0;i<21;i++)
			cin>>arr[i];
		for(int i = 2;i<21;i++)
		{
			cur = arr[i];
			for(int j = 1;j<i;j++)
			{
				if(cur<arr[j])
				{
					temp = cur;
					for(int k = i;k>j;k--)
					{
						arr[k] = arr[k-1];
						cnt++;
					}
					arr[j] = temp;
					break;
				}
				
			}
		}
		cout<<arr[0]<<" "<<cnt<<'\n';
	}

	return 0;
}