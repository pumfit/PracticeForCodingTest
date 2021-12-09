/*
14889 스타트와 링크

오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, 
i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.

팀을 어떻게 나눠야하지??에서 많이 고민한 문제이고 팀을 나누는 과정에서 Combination이 떠올라 이전 n과m에서 어떻게 변형해야 할까 까지 생각한 문제이다.
재귀를 통한 팀나누기 팀을 나누는 방법은 checked 배열을 이용해 check가 되어있으면 스타트팀 아니면 링크 팀으로 구분한다. 선택한 팀원이 N/2이 되는 경우 계산을 할때 이중 for문을 사용하여 같은 팀인 경우에만 능력치를 더하는 방식으로 각 팀의 능력치 합을 구한다.

해당 풀이에서 check를 통해 팀을 분리하는 방식과 cnt로 조건을 거는 방법을 몰라 문제풀이가 어려웠다.
이해를 하고 보니 풀이가 쉬워보이지만 백트래킹 종류의 문제를 많이 풀어봐야 할 것 같다.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 1e9;
int map[21][21] = { 0, };
int checked[21] = { 0, };

void Combination(int idx, int cnt)//cnt - 선택된 팀원의 수
{
	if (idx == N)
		return;
	if (cnt == N / 2)
	{
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (checked[i] && checked[j])
					sum1 += map[i][j];
				if (!checked[i] && !checked[j])
					sum2 += map[i][j];
			}
		}
		ans = min(ans, sum1 - sum2 >= 0 ? sum1 - sum2 : sum2 - sum1);
		return;
	}
	checked[idx] = true;
	Combination(idx + 1, cnt + 1);
	checked[idx] = false;
	Combination(idx + 1, cnt);
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	Combination(0, 0);
	cout << ans;
	return 0;
}