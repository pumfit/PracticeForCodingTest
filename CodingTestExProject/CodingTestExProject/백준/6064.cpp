/*
6064 카잉 달력

https://www.acmicpc.net/problem/6064
*/

// 시간 초과 풀이
#include <iostream>
using namespace std;

int gcd(int M, int N)
{
	return M == 0 ? N : gcd(N % M, M);
}

int main() {
	int T;
	cin >> T;
	int M, N, x, y;
	while (T--)
	{
		cin >> M >> N >> x >> y;

		int end = M > N ? M / gcd(M, N) * N : N / gcd(N, M) * M;
		while (end--)
		{
			if (end % M == x)
			{
				if (end % N == y)
				{
					cout << end << endl;
					break;
				}
			}
		}
		if (end == 0)
			cout << -1 << "\n";
	}
	return 0;
}

// 범위 한정 풀이

#include <iostream>
using namespace std;

int gcd(int M, int N)
{
	return M == 0 ? N : gcd(N % M, M);
}

int getYear(int N, int M, int x, int y)
{
	if (x == M)
		x = 0;
	if (y == N)
		y = 0;
	int end = M > N ? M / gcd(M, N) * N : N / gcd(N, M) * M;
	for (int i = x; i <= end; i += M)
	{
		if (i == 0)
			continue;
		if (i % N == y)
			return i;
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	int M, N, x, y;
	while (T--)
	{
		cin >> M >> N >> x >> y;
		cout << getYear(N, M, x, y) << "\n";
	}
	return 0;
}