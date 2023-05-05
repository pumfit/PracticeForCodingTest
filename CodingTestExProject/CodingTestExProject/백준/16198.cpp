/*
16198 에너지 모으기

N개의 에너지 구슬이 일렬로 놓여져 있고, 에너지 구슬을 이용해서 에너지를 모으려고 한다.

i번째 에너지 구슬의 무게는 Wi이고, 에너지를 모으는 방법은 다음과 같으며, 반복해서 사용할 수 있다.

에너지 구슬 하나를 고른다. 고른 에너지 구슬의 번호를 x라고 한다. 단, 첫 번째와 마지막 에너지 구슬은 고를 수 없다.
x번째 에너지 구슬을 제거한다.
Wx-1 × Wx+1의 에너지를 모을 수 있다.
N을 1 감소시키고, 에너지 구슬을 1번부터 N번까지로 다시 번호를 매긴다. 번호는 첫 구슬이 1번, 다음 구슬이 2번, ... 과 같이 매겨야 한다.
N과 에너지 구슬의 무게가 주어졌을 때, 모을 수 있는 에너지 양의 최댓값을 구하는 프로그램을 작성하시오.

사용한 i를 visited로 체크하고 visited된 (감소된) 배열을 제외하고 양쪽 옆을 계산해주면 되는 문제
처음에 생각한 대로 풀이를 이어갔더니 문제가 쉽게 풀렸다.
이제 좀 백트래킹 방식에 익숙해졌을지도..??

+)
leftIdx 짧게 줄여서 lIdx으로 쓰다보니 i대문자와 l이 헷갈리는데 어떤 표기법이 좋을지 고민하게 되었다.
단순하면서도 한번에 이해가는 변수명짓기...
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001] = { 0, };
int visited[1001] = { 0, };
int Max = 0;

void bt(int cnt, int sum)
{
	if (N - 2 == cnt)
	{
		Max = max(sum, Max);
		return;
	}
	for (int i = 1; i < N - 1; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			int rIdx = i;
			int lIdx = i;
			while (true)
			{
				if (visited[rIdx] == 0)
				{
					break;
				}
				rIdx++;
			}
			while (true)
			{
				if (visited[lIdx] == 0)
				{
					break;
				}
				lIdx--;
			}
			bt(cnt + 1, sum + arr[lIdx] * arr[rIdx]);
			visited[i] = 0;
		}

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	bt(0, 0);
	cout << Max;
	return 0;
}