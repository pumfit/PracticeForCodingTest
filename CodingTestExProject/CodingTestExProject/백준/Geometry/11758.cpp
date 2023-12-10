/*
11758 CCW
https://www.acmicpc.net/problem/11758

벡터의 외적을 활용하여 좌우 판별하는 문제
와중에 c++ 구조체 초기화하는 방법 까먹어서 다시 찾아봄

3차원 공간에서의 벡터의 외적은 두 벡터의 평면에 법선 벡터를 구할 수 있다.
이때 해당 법선 벡터가 양수라면 왼쪽 음수라면 오른쪽을 가리킨다.

외적 공식 및 정리는 이후에 정리하기
CCW( Counter Clock Wise) 알고리즘은 3개의 점 A, B, C가  있을 때 이 점 3개를 이은 직선의 방향을 알고자 할 때 유용한 

*/

#include <iostream>
using namespace std;

struct Vector
{
	int x;
	int y;
};

int main() {
	int x1,x2,x3,y1,y2,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	Vector v1 = {x2-x1,y2-y1};
	Vector v2 = {x3-x1,y3-y1};
	int w = v1.x*v2.y - v1.y*v2.x;
	if(w == 0)
		cout<<0;
	else if(w<0)
		cout<<-1;
	else
		cout<<1;
	return 0;
}