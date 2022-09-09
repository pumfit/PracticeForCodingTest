/*
2805 나무 자르기
https://www.acmicpc.net/problem/2805

풀이가 떠오르지않아서 답안 확인한 문제
원하는 값을 가지는 최소 값을 st = mid로 st값이 변화하지 않게 두는게 포인트인 문제이다.
	while (st < ed)
	{
		int mid = (st + ed + 1) / 2;
		if (isCanTimber(mid, ed))
		{
			st = mid; // st 고정
		}
		...
또한 이문제를 풀때 범위값을 잘 살펴야 하는데 값을 더하는 부분에서  (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000) 라서 N,M이 둘다 최대 값이라면
int 범위를 넘어설 수 있어 long long 형을 사용해야 풀이가 가능하다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

bool isCanTimber(int n, int ed)
{
	long long sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] <= n)
			continue;
		sum += v[i] - n;
	}
	cout << "sum : " << sum << ", mid : " << n << ", ed : " << ed << endl;
	return sum >= M;
}

int main() {
	cin >> N >> M;
	int n;
	while (N--)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	int st = 0;
	int ed = v[v.size() - 1];
	while (st < ed)
	{
		int mid = (st + ed + 1) / 2;
		if (isCanTimber(mid, ed))
		{
			st = mid; // st 고정
		}
		else
		{
			ed = mid - 1;
		}

	}
	cout << st;
	return 0;
}