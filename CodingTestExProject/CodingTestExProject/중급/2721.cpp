/*
2721 삼각수의 합
n번째 삼각수, T(n)은 1부터 n까지의 합이다. T(n) = 1 + ... + n. 이것은 삼각형 모양으로 표현할 수 있다.
다음과 같은 식을 통해 가중치를 부여한 삼각수의 합을 구할 수 있다.
W(n) = Sum[k=1..n; k*T(k+1)]

T(n)= n(n+1)/2 이므로  k*T(k+1)으로 (i*(i + 1)*(i + 2)) / 2 합을 구하면 되는 문제이다.
범위가 300이 넘어가게되면 시간을 줄일 수 있는 방법이 있을지 생각해보면 좋을 것 같다.

*/

#include<iostream>
using namespace std;

int main()
{
	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int N;
		int sum = 0;

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			sum += (i*(i + 1)*(i + 2)) / 2;
		}
		cout << sum << endl;
	}
}