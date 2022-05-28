/*
10819 차이를 최대로

N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.
|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

처음에 아무리 계산해도 최대가 32라 뭐지뭐지했는데 간격이 1인줄 알았다..깨닫고 for문 바꿔주고 바로 맞춘 문제

그리고 처음에 전체를 백트래킹해야한다 가 주요 포인트 였는데 백트래킹 구현이 잘 생각나지 않았다.
먼저 idx가 N인 경우 계산을 하도록 구현했고 이후 for문을 통해 재귀를 하도록 했다.
여기 까지 하고 출력해보니 중복이 난무해서 visited를 사용해 방문한 숫자를 사용하지 않도록 하여
모든 조합의 경우를 찾았다.
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int num[10];
int arr[10];
int visited[10] = { 0, };
int ans = 0;

void bt(int idx)
{
	if (idx == N)
	{
		int sum = 0;
		for (int i = 2; i <= N; i++)
			sum += abs(arr[i - 2] - arr[i - 1]);
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			arr[idx] = num[i];
			visited[i] = 1;
			bt(idx + 1);
			visited[i] = 0;
		}

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	bt(0);
	cout << ans;
	return 0;
}