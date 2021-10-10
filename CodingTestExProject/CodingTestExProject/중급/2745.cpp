/*
2745 진법 변환

내풀이
N진법의 숫자를 10진법으로 바꾸는 방법은 자릿수마다 N에 대한 자릿수 제곱을 곱해 더하면 10진법으로 표현할 수 있다.
이를 이용하여 풀이를 진행하고자 한다.

풀고나서 다른 풀이들도 살펴보았는데 파이썬 풀이의 경우 제곱이 간단하고 문법적으로 풀이가 짧았다.
이후에 파이썬으로도 풀었던 문제들을 바꿔서 풀어봐도 좋을 것 같다.

+) 아스키 코드표 보지 않고 풀어야한다.
기본적인 코드값은 외워두자
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string N;
	int B;
	long long ans = 0;
	cin >> N >> B;

	for (int i = N.length()-1;  0 <= i ; i--)
	{
		int num = 0;
		if ('A' <= N[i] && N[i] <= 'Z')
		{
			num = N[i] - 'A' + 10;
			for (int j = 0; j < N.length() - i - 1; j++)
			{
				num *= B;
			}
		}
		else
		{
			num = N[i] -48;
			for (int j = 0; j < N.length() - i - 1; j++)
			{
				num *= B;
			}
		}
		ans += num;
	}

	cout << ans;
}