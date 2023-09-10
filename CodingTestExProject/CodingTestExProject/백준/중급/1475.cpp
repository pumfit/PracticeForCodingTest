/*
1475 방번호
방번호를 받으면 0~9까지 수가 들어있는 세트가 몇개가 필요한지
배열을 만들고 안에서 예외처리

0 예외처리 안하고 34번 라인을 최대값 찾고 나서 하려고 해서 몇번이나 실패한 문제...
6과 9를 같은 수로 생각하는게 문제의 주요 포인트이다!
*/
#include<iostream>
using namespace std;

int main()
{
	int a;
	int max = 0;
	int num[10] = { 0, };

	cin >> a;

	if (a == 0)
	{
		num[0]++;
	}
	else
	{
		while (a != 0)
		{
			int n = a % 10 == 9 ?6: a % 10;
			num[n]++;
			a = a / 10;
		}

	}

	num[6] = num[6] % 2 == 0 ? num[6] / 2 : num[6] / 2 + 1;

	for (int i = 0; i < 10; i++)
	{
		if (max < num[i])
		{
			max = num[i];
		}

	}

	cout << max;
}