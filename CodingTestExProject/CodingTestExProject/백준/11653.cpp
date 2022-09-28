/*
11653 소인수분해

N에 대한 소인수 분해는 i = 2부터 나머지수가 0 인경우엔 나눠주고 아닌 경우에는 i 를 증가하는 방식으로 찾아가면된다. 

https://www.acmicpc.net/problem/11653
*/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int i = 2;
	while (N != 1)
	{
		if (N % i == 0)
		{
			cout << i << "\n";
			N /= i;
		}
		else
			i++;
	}
	return 0;
}