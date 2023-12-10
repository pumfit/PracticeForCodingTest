/*
1358 하키
https://www.acmicpc.net/problem/1358


원의 방정식을 활용하는 문제
(x-a)^2 + (y-b)^2 = r^2
직사각형 범위 내 또는 두 원 중 하나에 포함되면 링크안에 포함된다.
*/
#include <iostream>
using namespace std;
int W,H,X,Y,P;

bool FindPlayer(int x, int y)
{
	float r = H/(float)2;
	if(X<=x&&Y<=y&&x<=X+W&&y<=Y+H)
		return true;
	if((x-X)*(x-X)+(y-Y-r)*(y-Y-r)<=r*r)
		return true;
	if((x-X-W)*(x-X-W)+(y-Y-r)*(y-Y-r)<=r*r)
		return true;
	return false;
}

int main() {
	int answer = 0;
	cin>>W>>H>>X>>Y>>P;
	while(P--)
	{
	    int x,y;
	    cin>>x>>y;
	 	if(FindPlayer(x,y))
		    answer++;
	}
	cout<<answer;
	return 0;
}