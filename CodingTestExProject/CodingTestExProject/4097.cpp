/*
4097 수익

연종이는 창업했다. 오늘은 창업한지 N일이 되었고, 매일 매일 수익을 적어놓았다.
어느 날 연종이는 가장 많이 돈을 번 구간이 언제인지 궁금해졌다.
오늘이 창업한지 6일 되었고, 수익이 다음과 같다고 하자.

1일: -3
2일: 4
3일: 9
4일: -2
5일: -5
6일: 8
이때, 가장 많은 돈을 번 구간은 2~6까지이고 총 수입은 14이다.

기존에 풀었던 dp문제들과 매우 유사하고 테스트 케이스에 대한 처리만 하면 되는 문제라 쉽게 풀었다.

구간의 최대값을 memo에 저장한다. 날마다 해당일과 이전 memo값+해당일 중 큰 값을 최대값으로 정하게 된다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int N;
	while (true)
	{
		cin >> N;
		if (N == 0)
			return 0;
		else
		{
			int m = -10000;
			int arr[250001];
			int memo[250001];
			for (int i = 0; i < N; i++)
			{
				cin >> arr[i];
			}
			memo[0] = arr[0];
			for (int i = 1; i < N; i++)
			{
				memo[i] = max(arr[i], arr[i] + memo[i - 1]);
				m = max(m, memo[i]);
			}
			cout << m << endl;
		}
	}
	return 0;
}