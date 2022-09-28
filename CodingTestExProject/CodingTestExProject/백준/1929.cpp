/*
* 1929 �Ҽ� ���ϱ�
* https://www.acmicpc.net/problem/1929
* 
* 
* �Ʒ� Ǯ�� �ٽ� ����
* https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x12/solutions/1929.cpp
*/
#include <iostream>
using namespace std;

bool FindPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = N; i <= M; i++)
	{
		if (FindPrime(i))
			cout << i << " ";
	}
	return 0;
}
