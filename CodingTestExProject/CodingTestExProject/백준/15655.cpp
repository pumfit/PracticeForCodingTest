/*

15655 N과 M (6)

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
고른 수열은 오름차순이어야 한다.
"중복되는 수열을 여러 번 출력하면 안되며"이므로 이전 문제에서 재귀내 반복문의 i 시작값을 제어해주는 num을 만들어 풀이를 진행했다.

이전 (1),(2)문제와 유사하여 쉽게 풀 수 있었다.

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

void bf(int idx, int num)
{
	if (M == idx)
	{
		for (int i = 0; i < M; i++)
			cout << selected[i] << " ";
		return;
	}
	for (int i = num; i < N; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			selected[idx] = arr[i];
			bf(idx + 1, i);
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
	bf(0, 0);
	return 0;
}