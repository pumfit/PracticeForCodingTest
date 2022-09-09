/*
16401 과자 나눠주기
https://www.acmicpc.net/problem/16401

처음엔 문제를 이해를 못했다. 슥 보면 그냥 더해서 인원수대로 나누면 되는 게 아닌가 싶은데
"단, 막대 과자는 길이와 상관없이 여러 조각으로 나눠질 수 있지만, 과자를 하나로 합칠 수는 없다. " 하나로 합칠 수는 없다는 조건을 가지고 있다.
즉 10 10 15에서 15는 7,7까지만 나눠진다.

이분탐색으로 나눌 값을 찾고 그 값이 인원수만큼 잘라지는 지 확인하는 두가지 스텝으로 진행하면된다.
이때 최대가 되는 값을 찾아야하므로 ed값을 출력하면된다.
답이 없는 경우에는 ed가 0이 되므로 따로 예외 처리하지 않아도 된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, sum = 0;
vector<int> v;

bool IsCanShare(int n)
{
	int target = 0;
	for (int i = 0; i < M; i++)
	{
		int sum = v[i];
		while (sum - n >= 0)
		{
			sum -= n;
			target++;
			if (target == N)
				break;
		}
		if (target == N)
			break;
	}
	return target >= N;
}

int main() {
	int n;
	cin >> N >> M;
	int st = 0;	int ed = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> n;
		sum += n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	ed = v[v.size() - 1];
	int mid = 0;
	while (st <= ed)
	{
		mid = (st + ed) / 2;
		if (IsCanShare(mid))
		{
			st = mid + 1;
		}
		else
		{
			ed = mid - 1;
		}
	}

	cout << ed;
	return 0;
}