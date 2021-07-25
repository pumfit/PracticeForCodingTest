/*
2960 에라토스테네스의 체 ★★★

N보다 작거나 같은 모든 소수를 찾는 알고리즘
에서 K번째로 지우는 수가 무엇인지 찾는 문제

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