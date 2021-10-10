/*
2702 초6 수학

gcd 알고리즘을 복습하면서 삼항연산자로 구현 방식을 바꾸는 것을 연습해보았다. 
*/

#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		
		int g = gcd(A, B);
		cout << A * B / g << " " << g << endl;
	}
}