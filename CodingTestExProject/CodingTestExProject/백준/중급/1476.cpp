/*
1476 날짜 계산

E,S,M 범위내 숫자(1,2,...,15)가 동일하게 들어가는 경우 모두 0이 되므로 해당 숫자가 연도가 된다.
따라서, E 의 범위는 15, S의 범위는 28,M의 범위는 19로 연도를 year라고 할때 year에서 받아온
값을 뺀 값이 해당 범위의 배수여야 한다.

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