/*
1193 분수찾기

문제의 규칙을 찾기 위해 먼저 분수를 제외하고 지그재그로 숫자를 넣어보고 살펴보았다.
등차수열로 각 줄이 증가하고 홀/짝으로 바뀌며 대칭을 이루는 규칙을 볼 수 있었다.

따라서 이를 바탕으로 문제를 풀어나갔다.
먼저 N의 범위를 파악하고 이때 k,d값을 활용하여 분모,분자값을 계산했다.
*/

#include<iostream>
using namespace std;

int main()
{
	int N;

	cin >> N;

	int k = 1, d = 1;

	while (true)
	{
		if (N <= k) 
		{
			break;
		}
		else
		{
			d++;
			k += d;
		}	
	}

	int u = d % 2 == 0 ? d - k + N : k - N + 1;
	int b = d % 2 == 0 ? k - N + 1 : d - k + N;
	cout << u << "/" << b;
}