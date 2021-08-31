/*
1003 피보나치 함수

메모제이션을 사용하여 시간초과가 나지않도록 하였다.
이전 피보나치 수열 문제를 풀면서 배웠던 방법인데 0이 아닌 경우 해당값을 리턴해줘야 한다는 것을
생각하는데 조금 시간이걸렸다. 그리고 해당 문제의 답에 대한 힌트는 문제에 주어진 테스트에 있는데
이 규칙은 fibonacci(N - 1) << " " << fibonacci(N)임을 알 수 있다.

하지만, 0의 경우 fibonacci(- 1)이 들어가게 되므로 예외처리를 꼭 해주어야한다.
*/
#include<iostream>
using namespace std;

int fibo[40] = { 0, };

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (fibo[n] != 0) {
		return fibo[n];
	}
	else {
		
		return fibo[n] = fibonacci(n-1) + fibonacci(n-2);
	}
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		if (N == 0)
		{
			cout << 1 << " " << 0 << endl;
		}
		else
		{
			cout << fibonacci(N - 1) << " " << fibonacci(N) << endl;
		}
	}
}