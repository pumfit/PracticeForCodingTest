/*
5347 LCM

두 수 a와 b가 주어졌을 때, a와 b의 최소 공배수를 구하는 프로그램을 작성하시오.

최소공배수를 구하는 문제
최대공약수 복습할 수 있었던 좋은 문제
gcd 알고리즘 풀때 생각할 것
1. A에 큰수가 오도록 한다.
2. 예제를 나머지를 직접 풀어보며 구현해본다.
+) 백만x백만이라 int형아닌 long으로 바꿔야하는 문제였다 이것때문에 한번 틀림
*/
#include<iostream>
using namespace std;

long gcd(long a, long b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		long long A, B;
		cin >> A >> B;
		
		long k = A > B ? gcd(A, B) : gcd(B, A);
		cout<< A * B / k<<endl;
	}
	return 0;
}