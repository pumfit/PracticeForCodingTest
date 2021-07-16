/*
2506번 점수계산

이전에 풀어본 적 있는 문제 스타일

		if (b == 0)
		{
			num = 0;
		}
		else
		{
			num++;
		}
		
		부분을 삼항연산자로 줄여서 num = b == 0 ? 0 : num + 1; 로 고침

*/

#include<iostream>

using namespace std;

int main()
{
	int n,score=0,num=0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;

		num = b == 0 ? 0 : num + 1;
		score += num;
	}

	cout << score;
}