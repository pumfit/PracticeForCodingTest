/*
1010 다리놓기

예제외의 몇가지 예시를 해보면
Combination이 떠오른다.

*/

#include<iostream>
using namespace std;

long long arr[31];

long long Factorial(int n)
{
	if (n <= 1)
		return 1;
	if (arr[n] != 0)
	{
		cout << arr[n] << endl;
		return arr[n];
	}
	else
	{
		arr[n] = n * Factorial(n - 1);
		return arr[n];
	}
}


long long Combination(int a, int b)
{
	return Factorial(a) / (Factorial(a - b)*Factorial(b));
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;
		long long n = a >= b ? Combination(a, b) : Combination(b, a);
		cout << n << endl;
	}

}