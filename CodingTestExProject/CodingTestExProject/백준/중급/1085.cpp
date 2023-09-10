/*
1085 직사각형에서 탈출

이 문제도 자바에서 예전에 풀었을 때 틀렸었는데 풀이가 조금 달라졌다.
이번 풀이는 삼항연산자위주로 풀이를 진행하였다.
*/

#include <iostream>
using namespace std;

int main()
{
	int x, y, w, h ,min =0;

	cin >> x >> y >> w >> h;

	int xMin = w - x > x ? x : w - x;
	int yMin = h - y > y ? y : h - y;
	min = xMin > yMin ? yMin : xMin;
	
	cout << min;
}