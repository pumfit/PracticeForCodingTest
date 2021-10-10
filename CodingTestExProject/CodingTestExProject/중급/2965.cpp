/*
2965 캥거루 세마리

간격이 큰 경우 두 수 사이 간격에서 계속 이동해주면 되는 문제
왜인지 모르겠지만 while문으로 하나하나 다 세주고 있다가 채점하고나서
간격이니까 뺄셈으로 풀어도 된다는 걸 깨달았다.
	while (!(A == B || B == C))
	{
		if (C - B > B - A)
		{
			A = B;
			B = B + 1;
		}
		else
		{
			C = B;
			B = B - 1;
		}
		count++;
	}
	cout << count-1;
	로 풀어서 맞췄다가 더 짧은 아래 버전으로 다시 제출하고 맞췄다.
*/
#include<iostream>
using namespace std;

int main()
{
	int A, B, C;
	int count = 0;
	cin >> A >> B >> C;

		if (C - B > B - A)
		{
			cout << C - B - 1;
		}
		else
		{
			cout << B - A - 1;
		}
}