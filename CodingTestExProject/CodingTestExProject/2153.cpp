/*
2153 �Ҽ� �ܾ�

���ĺ� ��ҹ��ڷ� �̷���� ���� �ܾ �ϳ� ���� ��, a�� 1��, b�� 2��, ��, z�� 26����,
A�� 27��, ��, Z�� 52�� �Ͽ� �� ���� ���Ѵ�. ���� ��� cyworld�� ���� ���ϸ� 100�� �ǰ�, abcd�� 10�� �ȴ�.

�̿� ���� ���� ���� �Ҽ��� ���, �� �ܾ �Ҽ� �ܾ��� �Ѵ�. �ܾ �־����� ��, 
�� �ܾ �Ҽ� �ܾ����� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù�õ� �� �׽�Ʈ ���̽��� ���� �빮���� ��츸 �����ؼ� �빮�� A�� 1�� �ΰ� Ǯ���µ� ����Ǳ淡
�״�� �����ߴ��� �翬�� Ʋ�ȴ�. ������ �� �а� Ǯ�� ��
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