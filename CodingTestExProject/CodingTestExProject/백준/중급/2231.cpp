/*
2231 분해합

첫 생각:BF로 풀어보자

첫 풀이에 43번 라인에 K > N으로 지정해서 15와 같은 경우 12가 가능하지만 범위 때문에 막혔고
두번째 풀이에 K > N*2으로 설정해두었더니 12ms로 통과하였다.
속도를 줄이고자 생각해보았고 생성자가 분해합이 되기 위해서는 분해합 주위 일정 범위내 라고 생각할 수 있었다.
그래서 N의 나머지 값을 제외하여 범위를 지정하여 4ms으로 줄였다.
시작을 0에서 하지 않는다면 더 빨라 질 것 같은데 어떻게 범위를 설정해야하는 것이 올바른지 좀 더 생각해보아야 할 것 같다.
*/

#include<iostream>
using namespace std;

int getNum(int g)
{
	int temp = g;
	while (temp > 0)
	{
		g += temp % 10;
		temp /= 10;

	}
	return g;
}

int main()
{
	int N;
	int G = 0;
	cin >> N;

	while (true)
	{
		int k = getNum(G);
		if (k == N)
		{
			cout << G;
			break;
		}
		else if(k >N+N%10)
		{
			cout << 0;
			break;
		}
		else
		{
			G++;
		}
	}

}