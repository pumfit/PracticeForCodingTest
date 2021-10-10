/*
4948 베르트랑 공준

베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고,
2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.
이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.
예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다. 
(11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)
자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.

"n보다 크고, 2n보다 작거나 같은"

이미 증명된 명제이므로 n에 대한 검증 없이 2n이하의 소수를 찾으면 된다.
소수구하는 방식을 잊고있었다가 범위를 루트 이내만 구하면 되는 것만 기억나서 조금 해맸다.
1의 경우에 0이 나와 2가 포함되도록 1이 리턴되도록 예외처리를 따로 해주었다.
*/
#include<iostream>
using namespace std;

int countPrime(int n)
{
	int k = n+1;
	bool isPrime = true;
	int count = 0;
	while (k <= 2 * n)
	{
		for (int i = 2; i*i <= 2 * k; i++)
		{
			if (k%i == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			count++;
		}
		isPrime = true;
		k++;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return count;
	}

}

int main()
{
	int N = -1;
	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		cout<< countPrime(N)<<endl;
	}
}

