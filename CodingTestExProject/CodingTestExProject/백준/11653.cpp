/*
11653 ���μ�����

N�� ���� ���μ� ���ش� i = 2���� ���������� 0 �ΰ�쿣 �����ְ� �ƴ� ��쿡�� i �� �����ϴ� ������� ã�ư���ȴ�. 

https://www.acmicpc.net/problem/11653
*/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int i = 2;
	while (N != 1)
	{
		if (N % i == 0)
		{
			cout << i << "\n";
			N /= i;
		}
		else
			i++;
	}
	return 0;
}