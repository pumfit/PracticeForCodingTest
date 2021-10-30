/*
9507 Generations of Tribbles

꿍은 군대에서 진짜 할짓이 없다. 그래서 꿍만의 피보나치를 만들어보려고 한다. 
기존의 피보나치는 너무 단순해서 꿍은 좀더 복잡한 피보나치를 만들어보고자 한다. 그래서 다음과 같은 피보나치를 만들었다. 
꿍만의 피보나치 함수가 koong(n)이라고 할 때,
n < 2 :                         1
n = 2 :                         2
n = 3 :                         4
n > 3 : koong(n − 1) + koong(n − 2) + koong(n − 3) + koong(n − 4)
이다.

여러분도 꿍 피보나치를 구해보아라.

피보나치 수열 복습 + 메모기법
*/
#include<iostream>
using namespace std;

long long memo[68] = { 0, };

long long koong(int n)
{
	if (memo[n] != 0)
		return memo[n];
	if (n < 2)
		return memo[1];
	if (n == 2)
		return memo[2];
	if (n == 3)
		return memo[3];
	else
		return memo[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
}

int main()
{
	int T;
	cin >> T;
	memo[1] = 1; memo[2] = 2; memo[3] = 4;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout<< koong(n)<<endl;
	}
}