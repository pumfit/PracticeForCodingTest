/*
1476 ��¥ ���

E,S,M ������ ����(1,2,...,15)�� �����ϰ� ���� ��� ��� 0�� �ǹǷ� �ش� ���ڰ� ������ �ȴ�.
����, E �� ������ 15, S�� ������ 28,M�� ������ 19�� ������ year��� �Ҷ� year���� �޾ƿ�
���� �� ���� �ش� ������ ������� �Ѵ�.

*/

#include<iostream>
using namespace std;

int main()
{
	int E, S, M;
	int year = 0;

	cin >> E >> S >> M;

	while (true)
	{
		year++;
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0)
		{		
			cout << year;
			break;
		}
	}
}