/*2556 별 찍기 - 14


지금까지 안 나온 별 찍기가 뭐가 있는지 생각해본 후, 별을 적절히 찍으세요.

조금 어이없는 문제
기존 문제를 모두 풀어본 것이 아니라서 일단 질문을 보고 문제를 풀었다.
*/
#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}