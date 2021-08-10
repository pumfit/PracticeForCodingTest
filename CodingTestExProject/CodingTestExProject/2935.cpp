/*
2935 소음

첫째 줄에 양의 정수 A가 주어진다.
둘째 줄에 연산자 + 또는 *가 주어진다.
셋째 줄에 양의 정수 B가 주어진다.
A와 B는 모두 10의 제곱 형태이고, 길이는 최대 100자리이다.

연산자 처리만 잘해주면 되는 문제이다. 라고 생각했는데..
int main()
{
	int A, B;
	char O;

	cin >> A >> O >> B;

	if (O == '+')
	{
		cout << A + B;
	}
	else
	{
		cout << A * B;
	}
}
길이가 최대 100자리..100의 자리가 아니라 100자리다. 위와같이 int형으론 계산이 불가능하다 문제가 너무 쉽다했다. 여기서 한번 틀렸다.
그리고 덧셈에서 자릿수가 같은 55-59번라인을 생각하지않고 70,78번라인을 for문 안에 넣어서 두번 틀렸었다.
세번째 시도에 아래와 같은 코드로 통과하였다.

+)파이썬은 정말 숏코딩이 가능하구나 한번더 느낀 문제
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string A, B;
	string ans = "";
	char O;

	std::cin >> A >> O >> B;

	if (O == '+')
	{
		if (A.length() > B.length())
		{
			A[A.length() - B.length()] = '1';
			ans = A;
		}
		else if(A.length() < B.length())
		{
			B[B.length() - A.length()] = '1';
			ans = B;
		}
		else
		{
			A[0] = '2';
			ans = A;
		}

	}
	else
	{
		if (A.length() >= B.length())
		{
			for (int i = 0; i < B.length()-1; i++)
			{
				A = A.append("0");
			}
			ans = A;
		}
		else
		{
			for (int i = 0; i < A.length()-1; i++)
			{
				B = B.append("0");
			}
			ans = B;
		}
	}
	cout << ans;
}