/*
16967. 배열 복원하기
https://www.acmicpc.net/problem/16967

크기가 H × W인 배열 A와 두 정수 X와 Y가 있을 때, 크기가 (H + X) × (W + Y)인 배열 B는 배열 A와 배열 A를 아래로 X칸, 오른쪽으로 Y칸 이동시킨 배열을 겹쳐 만들 수 있다. 수가 겹쳐지면 수가 합쳐진다.

즉, 배열 B의 (i, j)에 들어있는 값은 아래 3개 중 하나이다.

(i, j)가 두 배열 모두에 포함되지 않으면, Bi,j = 0이다.
(i, j)가 두 배열 모두에 포함되면, Bi,j = Ai,j + Ai-X,j-Y이다.
(i, j)가 두 배열 중 하나에 포함되면, Bi,j = Ai,j 또는 Ai-X,j-Y이다.
배열 B와 정수 X, Y가 주어졌을 때, 배열 A를 구해보자.

구현 문제로 겹쳐지는 부분에 대해서 처리해주면 된다.
그림으로 그려보면 쉽게 확인이 가능하다.

*/
#include <iostream>
using namespace std;

int H, W, X, Y;
int B[1001][1001] = {0,};

int main() {
	cin>>H>>W>>X>>Y;
	for(int y = 0;y<(H+X);y++)
	{
		for(int x = 0;x<(W+Y);x++)
		{
			cin>>B[x][y];
		}
	}
	for(int y = 0;y<H;y++)
	{
		for(int x = 0;x<W;x++)
		{
			if(x>=Y&&y>=X)
			{
				B[x][y] = B[x][y] - B[x-Y][y-X];
			}
			
		}
	}
	for(int y = 0;y<H;y++)
	{
		for(int x = 0;x<W;x++)
		{
			cout<<B[x][y]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}