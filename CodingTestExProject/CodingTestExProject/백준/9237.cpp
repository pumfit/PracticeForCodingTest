/*
9237 이장님 초대

농부 상근이는 마당에 심기 위한 나무 묘목 n개를 구입했다. 묘목 하나를 심는데 걸리는 시간은 1일이고, 상근이는 각 묘목이 다 자라는데 며칠이 걸리는지 정확하게 알고 있다.
상근이는 마을 이장님을 초대해 자신이 심은 나무를 자랑하려고 한다. 이장님을 실망시키면 안되기 때문에,
모든 나무가 완전히 자란 이후에 이장님을 초대하려고 한다. 즉, 마지막 나무가 다 자란 다음날 이장님을 초대할 것이다.
상근이는 나무를 심는 순서를 신중하게 골라 이장님을 최대한 빨리 초대하려고 한다. 이장님을 며칠에 초대할 수 있을까?

"즉, 마지막 나무가 다 자란 다음날"이고 최대한 빨리 초대하므로  묘목이 자라는 시간이 오래 걸리는 묘목이면 앞에 위치해야한다.
따라서 정렬을 통해 배열을 정리하고 심는날짜 (i+1) +다음날 1를 해준 값중 최대값을 찾으면 되는 문제이다.

이전 그리디 프로젝트 팀 문제와 아주 유사한 문제로 처음에 읽으면서 dp인가 하다가 정해진 조건때문에 그리디로 풀수 있는 것을
알 수 있다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0, answer = 0;
	int arr[100001];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N, greater<int>());
	for (int i = 0; i < N; i++)
		answer = max(answer, arr[i] + 2 + i);
	cout << answer;
	return 0;
}