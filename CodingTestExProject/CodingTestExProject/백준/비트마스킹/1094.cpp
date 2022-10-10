/*
1094 막대기

https://www.acmicpc.net/problem/1094

이 문제는 계속 절반으로 나눠서 그 막대기 합을 구하는 문제인데 결국 이진수로 변환한 후 1값의 개수를 찾는 문제라는 걸 알 수 있다.
간단하게 이진수 변환을 진행하면서 X%2==1 일 경우 답을 증가하면 쉽게 통과할 수 있는 문제이다.

하지만 해당 문제의 풀이는 다르게 진행할 수 있다.

바로 비트마스킹의 기법중 하나인 자리수에 대한 비트 유무 검사를 통해 풀이가 가능하다.

 X & (1 << i) 으로 i 는 자리수가 된다.

 (1<<i)는 비트연산자를 통해 1<<0 = 1 0001 ,1<<1 = 2 0010, 1<<2 = 4 0100, 1<<3 = 8, 1<<4 = 16 1000, ...  자리수를 이동하며 증가하게된다.

A & B 는 A와 B의 모든 비트를 AND 연산을 진행한다. 
1101 & 1000 이라면 1000이 결과값으로 나온다.

따라서 (1 << i)로 순차적으로 & 연산을 진행하면 해당 자리수에 비트가 1인지 아닌지를 확인할 수 가 있다.

- X가 64 라고 명시적으로 주어진 이유 (범위 제한)

*/

#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	int cnt = 0;
	for (int i = 0; i < 7; i++)
	{
		if (X & (1 << i))
			cnt++;
	}
	cout << cnt;
	return 0;
}

// 비트마스킹 사용하지 않는 풀이
#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	int cnt = 0;
	while (X > 0)
	{
		if (X % 2 == 1)
			cnt++;
		X /= 2;
	}
	cout << cnt;
	return 0;
}