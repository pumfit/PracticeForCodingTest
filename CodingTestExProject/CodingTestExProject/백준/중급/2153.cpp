/*
2153 소수 단어

알파벳 대소문자로 이루어진 영어 단어가 하나 있을 때, a를 1로, b를 2로, …, z를 26으로,
A를 27로, …, Z를 52로 하여 그 합을 구한다. 예를 들어 cyworld는 합을 구하면 100이 되고, abcd는 10이 된다.

이와 같이 구한 수가 소수인 경우, 그 단어를 소수 단어라고 한다. 단어가 주어졌을 때, 
그 단어가 소수 단어인지 판별하는 프로그램을 작성하시오.

첫시도 때 테스트 케이스만 보고 대문자인 경우만 생각해서 대문자 A를 1로 두고 풀었는데 통과되길래
그대로 제출했더니 당연히 틀렸다. 문제를 잘 읽고 풀자 꼭
*/

#include<iostream>
#include<string>
using namespace std;

void isPrime(int n)
{
	bool isPrime = true;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			cout << "It is not a prime word.";
			isPrime = false;
			break;
		}
	}
	if(isPrime)
		cout << "It is a prime word.";
}

int main()
{
	string S;
	int sum = 0;

	cin >> S;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i]>'Z')
		{
			sum += S[i] - 96;
		}
		else
		{
			sum += S[i] - 38;
		}

	}

	isPrime(sum);
}