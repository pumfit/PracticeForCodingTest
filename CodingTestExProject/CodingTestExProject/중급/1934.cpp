/*
1934 최소공배수

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
	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

int main()
{
	int N;
	int A, B;

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		cout << A * B / gcd(A, B)<<endl;
	}
}