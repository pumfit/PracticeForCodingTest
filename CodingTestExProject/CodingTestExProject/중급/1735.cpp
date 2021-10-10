/*
1735 분수 합

내 풀이
기존 분수 풀이 처럼 더한 후 두 분자 분모의 최대공약수를 구한 뒤
해당값으로 나눠주어서 풀이하였다.

gcd 알고리즘을 이전에 익혀두었더니 쉽게 풀 수 있었던 문제
*/
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	
	int g = gcd(A*D + B * C, B*D);
	cout << (A*D + B * C) / g << " "<<B * D / g;

}