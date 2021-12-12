/*
15657 N과 M(8)

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 자연수는 모두 다른 수이다.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

또 다시 돌아온 N과 M 잘한점 - 풀이 도움없이 풀음,
못한점 - 처음에 무지성으로 visited 검사했는데 문제를 보니 중복이 들어가서 지웠다. select를 vector로 지정해서 depth 지정없이 넣어주어서 값이 모두 첫번째 값만 나오는 경험을 했다.
배열의 순서를 위해 depth(인덱스 순서)대로 값을 넣어주어야한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int selected[9] = { 0, };

void bt(int depth, int num)
{
	if (M == depth)
	{
		for (int i = 0; i < M; i++)
			cout << selected[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = num; i < N; i++)
	{
		selected[depth] = v[i];
		bt(depth + 1, i);
	}
}

int main() {
	cin >> N >> M;
	int n;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	bt(0, 0);
	return 0;
}