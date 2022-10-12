/*
2961 도영이가 만든 맛있는 음식

해당 문제를 풀기 위해선 부분집합을 모두 구한뒤 값을 계산해 가장 차이가 작은 경우를
찾으면 될 것 같다고 생각했다.

기존에는 부분집합을 next_permutation으로 구했었는데

비트마스킹을 사용한 풀이를 진행해보았다.
기존에 진행했던 비트의 유무판단을 사용하면 쉽게 부분집합을 구할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, S, B;
	int answer = 2e9;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> B;
		v.push_back({ S,B });
	}
	int sumS = 1, sumB = 0; int sum = 0;
	for (int i = 1; i < (1 << N); i++) // 공집합은 포함하지않는다.
	{
		for (int k = 0; k < N; k++)//0~(N-1) N 자리수 
		{
			if (i & (1 << k))
			{
				sumS *= v[k].first;
				sumB += v[k].second;
			}
		}

		sum = sumS - sumB > 0 ? sumS - sumB : sumB - sumS;
		answer = min(answer, sum);
		sumS = 1; sumB = 0;
	}
	cout << answer;
	return 0;
}
