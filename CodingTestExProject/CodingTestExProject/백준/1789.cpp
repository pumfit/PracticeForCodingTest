/*
1789 수들의 합

서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?

서로 다른 N개의 자연수가 최대값으로 구성도므로 1부터 시작해야하며 해당되는 S까지 
계속 더하다가 sum을 넘긴 경우 cnt 값보다 한번 작은 횟수가 자연수 N의 최댓값이 된다.

for문 밖에 i를 선언해 i값을 cnt로 쓰는게 더 효율적일 것 같다.
*/
#include <iostream>
using namespace std;

int main() {
	long long N;
	long long sum = 0;
	int cnt = 0;
	cin >> N;
	for (int i = 1; i < 2e9; i++)
	{
		if (sum > N)
			break;
		sum += i;
		cnt++;
	}
	cout << cnt - 1;
	return 0;
}