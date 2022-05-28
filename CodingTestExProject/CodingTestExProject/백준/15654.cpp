/*

15654 N과 M (5)

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
문제를 제대로 읽지않고 N개의 자연수를 이전 문제들 처럼 1~N개의 자연수로 착각해서 조금 해맸다.

arr에 받아와 자연수를 받아온 후 정렬을 하고 진행하여 사전 순으로 증가하는 순서로 출력되게 하였다.

*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int n;
vector<int> arr;
int selected[9] = { 0, };
int visited[9] = { 0, };

void bf(int idx)
{
	if (M == idx)
	{
		for (int i = 0; i < M; i++)
			cout << selected[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			selected[idx] = arr[i];
			bf(idx + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end());

	bf(0);
	cout << '\n';
	return 0;
}