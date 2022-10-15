/*
1052 물병

https://www.acmicpc.net/problem/1052

다시풀기
*/
#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int cnt = 0; int sum = 0;
	while (N > 0)
	{
		int i = 0;
		while ((1 << i + 1) < N)
		{
			i++;
		}
		N = N - (1 << i);
		if (cnt == K - 1)
		{
			cout << (1 << i) - N << endl;
			return 0;
		}
		cnt++;
	}
	cout << -1 << endl;
	return 0;
}