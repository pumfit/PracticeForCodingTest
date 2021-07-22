/*
2609 최대공약수 와 최소공배수

1934 최소공배수에서의 유클리드 호제법 알고리즘을 사용한다.

유클리드 호제법
입력으로 두 수 m,n(m>n)이 들어온다.
n이 0이라면, m을 출력하고 알고리즘을 종료한다.
m이 n으로 나누어 떨어지면, n을 출력하고 알고리즘을 종료한다.
그렇지 않으면, m을 n으로 나눈 나머지를 새롭게 m에 대입하고, m과 n을 바꾸고 3번으로 돌아온다.

*/

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	int n;
	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}
int main()
{
	int N = 0;
	int A, B;

	cin >> A >> B;
	N = gcd(A, B);
	cout << N << "\n" << A * B / N;

}