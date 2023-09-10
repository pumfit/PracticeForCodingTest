/*
2312 수 복원하기

양의 정수 N이 주어졌을 때, 이 수를 소인수분해 한 결과를 출력하는 프로그램을 작성하시오.

오류 없이 한번에 원샷코딩했다.
약수 나눠주면서 출력되도록 문제풀이를 진행하였다.
*/
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		
		int k = 2;

		while (N!=1)
		{
			if (N%k == 0)
			{
				int d = 0;
				while (N%k == 0)
				{
					d++;
					N /= k;
				}
				cout << k << " " << d << endl;
			}
			else
			{
				k++;
			}
		}

	}
}