/*
1644 소수의 연속 합

https://www.acmicpc.net/problem/1644

소수의 체로 N까지의 소수를 구하고 투포인터를 통해 풀면 되는 문제

			if (ed == v.size())
				break;

	해당 조건을 sum이 N이되는 후에 넣었다가 96퍼쯤에 틀렸었는데 예외를 찾기가 어려웠다.
	예외인 경우는 2인 경우로 st == ed == 0인 경우 해당되는 조건에서 예외가 생긴다.
	인덱스 조건이므로 인덱스 더해준 바로 다음 조건 체크해줘야하고 테케 여러 경우 해보면 좋겠다는 생각이 든 문제

+) 해당 풀이로 N의 최대값인 4,000,000를 넣으면 1이 나오고 1.49s 정도 소요된다.
*/

#include <iostream>
#include <vector>
using namespace std;

bool CheckPrimeNum(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	int N;
	cin >> N;
	vector<int> v;
	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		if (CheckPrimeNum(i))
		{
			v.push_back(i);
			if (i == N)
				answer++;
		}
	}
	int sum = 0; int ed = 0;
	for (int st = 0; st < v.size(); st++)
	{
		while (sum <= N)
		{
			if (ed == v.size())
				break;
			if (sum == N)
			{
				answer++;
				break;
			}
			sum += v[ed];
			ed++;
		}
		if (ed == v.size())
			continue;

		sum -= v[st];
	}
	cout << answer;
	return 0;
}