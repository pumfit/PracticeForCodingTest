/*
2563 색종이
https://www.acmicpc.net/problem/2563


*/
#include <iostream>
using namespace std;

int main() {
	int map[101][101] = {0,};
	int N;
	int x,y,answer = 0;
	cin>>N;
	
	while(N--)
	{
		cin>>x>>y;
		for(int i = y;i<y+10;i++)
		{
			for(int j = x;j<x+10;j++)
			{
				map[j][i] = 1;
			}
		}
	}
	
	for(int i = 0;i<100;i++)
	{
		for(int j = 0;j<100; j++)
		{
			if(map[j][i]==1)
				answer++;
		}
	}
	cout<<answer;
	return 0;
}