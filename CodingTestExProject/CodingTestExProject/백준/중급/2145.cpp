/*
2145 숫자 놀이
주어진 숫자의 각 자릿수를 더한다.
결과가 한 자릿수가 될 때 까지 규칙1을 반복한다.
(마지막 입력은 0이며, 0에 대한 결과는 출력하지 않는다.)

0이 들어올때 마지막 \n 제거하는 방법 or 다른 반례가 있나??
반례 main의 while 문은 N > 10이 아닌 N >= 10이다.
*/
#include<iostream>
using namespace std;

int sum(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10; //3+7
		n = n / 10;//67 6
	}

	return sum;
}


int main()
{
	while (true)
	{
		int N = 0, SUM = 0;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		else
		{
			while (N >= 10)
			{
				N = sum(N);
			}
			cout << N << "\n";
		}

	}

}