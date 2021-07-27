/*
1676 팩토리얼 0의 개수

문제가 짧아서 이해하지 못 하고 있다가
테스트 케이스 직접 계산해보고 이해했다.

팩토리얼 계산내에 10의 배수가 되는 수가 얼마나 되는지 계산한다.
즉 10, (10의 배수가아닌) 5,(10의 배수가아닌) 2 배수의 개수를 구하면 된다.

문제 이해하고 아닌 경우 조건에서 탈출하게 하는 것이 이번 문제풀이의 포인트 인 것 같다.
*/

#include<iostream>
using namespace std;

int main()
{
	int N;
	int F = 0,T = 0;
	int ans = 0;

	cin >> N;

	while (N > 0)
	{
		int temp = N;
		while (true)
		{
			if (temp % 10 == 0)
			{
				ans++;
				temp /= 10;
			}
			else if (temp % 5 == 0)
			{
				F++;
				temp /= 5;
			}
			else if (temp % 2 == 0)
			{
				T++;
				temp /= 2;
			}
			else
			{
				break;
			}
		}
		N--;
	}
	ans += F >= T ? T : F;
	cout << ans;
}