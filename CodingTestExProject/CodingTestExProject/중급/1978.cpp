/*
1978 소수찾기

소수와 관련된 알고리즘인 "에라토스테네스의 체"에 대해 검색해보고 해당 문제를 풀어나갔다.

한번 틀렸었던 이유는 4가 소수로 판명되지 않았기 때문인데
해당 방식은 수 N에 대해 제곱근까지 나눠지는 지 구하는 방식으로
j*j < N이라고 생각했는데 N=4인 경우가 포함되지않았었다.

*/
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int ans = T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		if (N == 1)
		{
			ans--;
		}
		else
		{
			for (int j = 2; j*j < N; j++)
			{
				if (N%j == 0)
				{
					ans--;
					break;
				}
			}
		}
	}
	cout << ans;
}