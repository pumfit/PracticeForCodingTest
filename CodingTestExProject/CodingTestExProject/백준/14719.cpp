/*
14719 빗물

https://www.acmicpc.net/problem/14719

전체 탐색하면서 벽이 막힌 경우 답을 더한다.
벽이 하나인 경우, 붙어있는 경우 등의 예외처리가 필요하다. 500 x 500 이상으로 가면 이렇게 전체탐색하면 절대 안 될듯 
*/
#include <iostream>
using namespace std;

int main() {
	int H,W;
	cin>>H>>W;
	
	int arr[W] = {0,};
	int answer = 0;
	
	for(int i = 0;i<W; i++)
		cin>>arr[i];

	for(int i = 0;i<H;i++)
	{
		int count = 0; int wall = 0;
		for(int j = 0;j<W;j++)
		{
			if(arr[j]-i>0)
			{
				wall++;
				if(wall==2)
				{
					answer += count;
					wall--;
					count = 0;
				}
			}else if(wall>0){
				count++;
			}
		}
	}
	cout<<answer;
	return 0;
}