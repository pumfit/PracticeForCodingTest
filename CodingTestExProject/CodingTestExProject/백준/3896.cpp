/*
3896 소수 사이 수열

연속한 소수 p와 p+n이 있을 때, 그 사이에 있는 n-1개의 합성수(소수나 1이 아닌 양의 정수)는 길이가 n인 소수 사이 수열라고 부른다.
양의 정수 k가 주어졌을 때, k를 포함하는 소수 사이 수열의 길이를 구하는 프로그램을 작성하시오. 
k를 포함하는 소수 사이 수열이 없을 때는 길이가 0이다.
예를 들어, 소수 23과 29의 소수 사이 수열은 {24, 25, 26, 27, 28}이고, 길이는 6이다.

메인을 먼저 작성할때 들어오는 K(풀이에서는 N)에 대해 소수인경우 0이 되므로 K의 경계가 포함되게 K보다 크거나 같은 소수 - K보다 작거나 같은 소수로
up,down 함수를 두개 만들어 소수를 계산하게 했다.
에라토스테네스의 체를 이용했고 소수인 경우 return 하도록 했다.

범위가 범위이다보니 소수인 경우가 필수적으로 생기는데 이런 경우에도 for문 밖에 return값을 해주는게 맞나? 라는 의문이 들었다.
이번 풀이는 없이 제출했고 예외가 없다보니 통과했다.

+)
문제를 읽을때 자세히 읽는 습관을 기르자 문제 파악을 잘 해야 확실히 빠르게 풀 수 있다
*/
#include <iostream>
using namespace std;

int up(int N)
{
	for (int i = N; i <= 1299709; i++)
	{
		bool isPrime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			return i;
		}
	}
}

int down(int N)
{
	for (int i = N; 2 <= i; i--)
	{
		bool isPrime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i%j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			return i;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << up(N) - down(N) << endl;
	}
	return 0;
}