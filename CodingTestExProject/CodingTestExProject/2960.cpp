/*
2960 �����佺�׳׽��� ü �ڡڡ�

N���� �۰ų� ���� ��� �Ҽ��� ã�� �˰���
���� K��°�� ����� ���� �������� ã�� ����

*/

#include <iostream>
using namespace std;

int main()
{
	int N, K;
	int Idx= 0;
	bool arr[1001] = { 0, };

	cin >> N >> K;

	for (int i = 2; i < N; i++)
	{
		if (arr[i] == 0)
		{

			for (int j = i; j < N; j += i)
			{
				Idx++;

				if (arr[j] == 0)
				{
					arr[j] = 1;
				}
				if (Idx == K)
				{
					cout << j;
					break;
				}
			}

		}
		if (Idx == K)
		{
			break;
		}
		
	}

}
/*

#include <iostream>
using namespace std;

int main()
{
	int N, K;
	int Idx= 0;
	bool arr[1001] = { 0, };

	cin >> N >> K;

	for (int i = 2; i < N; i++)
	{
		if (arr[i] == 0)
		{

			for (int j = i; j < N; j += i)
			{
				Idx++;

				if (arr[j] == 0)
				{
					arr[j] = 1;
				}
				if (Idx == K)
				{
					cout << j;
					break;
				}
			}

		}
		if (Idx == K)
		{
			break;
		}

	}

}

*/